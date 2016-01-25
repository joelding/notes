/**
 * udpsend3.c : a simple udp transmitter
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
	struct addrinfo *res, *p;
	char *s;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s dest_ip_addr\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	errcode =  getaddrinfo(argv[1], "12345", &hints, &res);
	if (errcode)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errcode));
		exit(EXIT_FAILURE);
	}

	for (p = res; p != NULL; p = p->ai_next)
	{
		switch (res->ai_family)
		{
			case AF_INET:
				s = "IPv4";
				break;
			case AF_INET6:
				s = "IPv6";
				break;
			default:
				s = "UNKNOWN";
				break;
		}
		fprintf(stdout, "%s\n", s);

		/* 1. create an endpoint for communication */
		sockfd = socket(p->ai_family, p->ai_socktype , 0);
		if (sockfd < 0)
		{
			perror("socket: ");
			exit(EXIT_FAILURE);
		}

		/* 2. send a message on a socket */
		errcode = sendto(sockfd, buf, sizeof(buf), 0, p->ai_addr, p->ai_addrlen);
		if (errcode < 0)
		{
			perror("sendto: ");
		}
	
		close(sockfd);

		if (errcode > 0)
			break;
	}

	freeaddrinfo(res);

	return 0;
}
