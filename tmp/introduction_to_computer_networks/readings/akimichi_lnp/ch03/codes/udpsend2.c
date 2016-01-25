/**
 * udpsend2.c : a simple udp transmitter
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

#define BUFSIZE	2048
	
int main(int argc, char *argv[])
{
	int sockfd;
#if 0
	struct sockaddr_in addr;
#endif
	char buf[BUFSIZE] = "HELLO";
	struct addrinfo hints;
	int errcode;
	struct addrinfo *res;
	char *p;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s dest_ip_addr\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* network address and service translation */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	errcode =  getaddrinfo(argv[1], "12345", &hints, &res);
	if (errcode)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errcode));
		exit(EXIT_FAILURE);
	}

	/* 1. create an endpoint for communication */
	sockfd = socket(res->ai_family, res->ai_socktype , 0);
	if (sockfd < 0)
	{
		perror("socket: ");
		exit(EXIT_FAILURE);
	}

	/* 2. send a message on a socket */
#if 0
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = INADDR_ANY;
	inet_pton(AF_INET, argv[1], &addr.sin_addr.s_addr); 
	errcode = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, sizeof(addr));
#else
	switch (res->ai_family)
	{
		case AF_INET:
			p = "IPv4";
			break;
		case AF_INET6:
			p = "IPv6";
			break;
		default:
			p = "UNKNOWN";
			break;
	}
	fprintf(stdout, "%s\n", p);

	errcode = sendto(sockfd, buf, sizeof(buf), 0, res->ai_addr, sizeof(struct addrinfo));
#endif
	if (errcode < 0)
	{
		perror("sendto: ");
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(res);
	close(sockfd);

	return 0;
}
