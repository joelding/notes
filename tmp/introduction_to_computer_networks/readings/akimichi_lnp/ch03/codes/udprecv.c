/**
 * udprecv.c : a simple udp receiver
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

#define BUFSIZE	2048

int main(int argc, char *argv[])
{
	int sockfd;
	int res;
	struct sockaddr_in addr;
	struct sockaddr_in sndinfo;
	socklen_t addrlen;
	char buf[BUFSIZE];
	ssize_t n;

	/* 1. create an endpoint for communication */
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		perror("socket: ");
		exit(EXIT_FAILURE);
	}

	/* 2. bind a name to a socket */
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = INADDR_ANY;
	res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
	if (res < 0)
	{
		perror("bind: ");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "listening...\n");
	fflush(stdout);

	/* 3. receive a message from a socket */
	memset(buf, 0, sizeof(buf));
	addrlen = sizeof(sndinfo);
	n = recvfrom(sockfd, buf, sizeof(buf) - 1, 0, (struct sockaddr *)&sndinfo, &addrlen);

	write(fileno(stdout), buf, n);
	write(fileno(stdout), "\n", 1);

	close(sockfd);

	return 0;
}
