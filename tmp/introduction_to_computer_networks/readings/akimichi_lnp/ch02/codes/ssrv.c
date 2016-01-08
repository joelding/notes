/* ssrv.c: simple TCP server
 */
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <errno.h>
#include <string.h>

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

	/* 2. set IP address and port */
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = INADDR_ANY; /* local host address */
	
	/* 3. assign a name to a socket */
	bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

	/* 4. listen for connections on a socket */
	if (listen(sockfd, 1) < 0) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, strerror(errno));
		return 1;
	}

	/* 5. accept a connection on a socket */
	addrlen = sizeof(socklen_t);
	if ((asock = accept(sockfd, (struct sockaddr *)&addr, &addrlen)) < 0) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, strerror(errno));
		return 1;
	}

	/* 6. start communication */
	write(asock, "HELLO", 5);
	close(asock);

	close(sockfd);

	return 0;
}
