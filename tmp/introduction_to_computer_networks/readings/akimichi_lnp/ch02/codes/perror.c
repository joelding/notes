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

	/* 1. create an endpoint for communication */
	sockfd = socket(3000, 4000, 5000); /* IPv4 TCP */
	if (sockfd < 0) {
//		fprintf(stderr, "%s@%d %s\n", __FILE__, __LINE__, strerror(errno));
		perror("perror.c");
		return 1;
	}

	close(sockfd);

	return 0;
}
