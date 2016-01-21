#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int sockfd; /* a file descriptor for the new socket */

	printf("fileno(stdin) = %d\n", fileno(stdin));
	//close(0);

	sockfd = socket(AF_INET, SOCK_STREAM, 0); /* IPv4 TCP */
	if (sockfd < 0) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, strerror(errno));
		return 1;
	}

	printf("sockfd = %d\n", sockfd);
	close(sockfd);

	return 0;
}
