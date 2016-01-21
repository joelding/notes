/* nobind.c: simple TCP server without calling bind
 * usage: client call $ telnet localhost port
 */
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <errno.h>
#include <string.h>

#include <arpa/inet.h>

static void print_net_info(int sockfd)
{
	char buf[48] = {0};
	struct sockaddr_in addr;
	socklen_t addrlen = sizeof(struct sockaddr_in);

	if (getsockname(sockfd, (struct sockaddr *)&addr, &addrlen) < 0) {
		perror("");
		return;
	}

	/* convert IPv4 and IPv6 addresses from binary to text form */
	if (!inet_ntop(AF_INET, &addr.sin_addr, buf, sizeof(buf))) {
		perror("");
		return;
	}

	/* ntohs: convert values between host and network byte order */
	fprintf(stdout, "%s:%d\n", buf, ntohs(addr.sin_port));
}

int main(int argc, char *argv[])
{
	int sockfd; /* a file descriptor for the new socket */
	struct sockaddr_in addr;
	socklen_t addrlen;
	int asock; /* a descriptor for the accepted socket */

	/* 1. create an endpoint for communication */
	sockfd = socket(AF_INET, SOCK_STREAM, 0); /* IPv4 TCP */
	if (sockfd < 0) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, strerror(errno));
		return 1;
	}
#if 0
	/* 2. set IP address and port */
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = INADDR_ANY; /* local host address */
	
	/* 3. assign a name to a socket */
	bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
#endif
	/* 4. listen for connections on a socket */
	fprintf(stdout, "listening...\n");
	if (listen(sockfd, 1) < 0) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, strerror(errno));
		return 1;
	}

	print_net_info(sockfd);

	/* 5. accept a connection on a socket */
	addrlen = sizeof(socklen_t);
	if ((asock = accept(sockfd, (struct sockaddr *)&addr, &addrlen)) < 0) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, strerror(errno));
		return 1;
	}
	fprintf(stdout, "accepted...\n");

	/* 6. start communication */
	write(asock, "HELLO", 5);

	close(asock);

	close(sockfd);

	return 0;
}
