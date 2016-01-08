/* scli.c : simple TCP client 
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int sockfd; /* a file descriptor for the new socket */
	struct sockaddr_in server;
	char buf[32];
	int n;

	/* 1. create an endpoint for communication */
	sockfd = socket(AF_INET, SOCK_STREAM, 0); /* IPv4 TCP */
	if (sockfd < 0) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, strerror(errno));
		return 1;
	}

	/* 2. set IP address and port */
	server.sin_family = AF_INET;
	server.sin_port = htons(12345);

	/* 3. connect */
	/* convert IPv4 and IPv6 serveresses from text to binary formi */
	inet_pton(AF_INET,"127.0.0.1", &server.sin_addr.s_addr);

	if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, strerror(errno));
		return 1;
	}

	/* 4. start communication */
	memset(buf, 0, sizeof(buf));
	n = read(sockfd, buf, sizeof(buf));
	fprintf(stdout, "%d, %s\n", n, buf);

	close(sockfd);

	return 0;
}
