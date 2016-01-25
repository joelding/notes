/**
 * udpsend.c : a simple udp transmitter
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFSIZE	2048
	
int main(int argc, char *argv[])
{
	int sockfd;
	int res;
	struct sockaddr_in addr;
	char buf[BUFSIZE] = "HELLO";

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s dest_ip_addr\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 1. create an endpoint for communication */
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		perror("socket: ");
		exit(EXIT_FAILURE);
	}

	/* 2. send a message on a socket */
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	inet_pton(AF_INET, argv[1], &addr.sin_addr.s_addr); 

	res = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, sizeof(addr));
	if (res < 0)
	{
		perror("sendto: ");
		exit(EXIT_FAILURE);
	}

	close(sockfd);

	return 0;
}
