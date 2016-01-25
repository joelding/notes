/**
 * udpgrecv.c : a simple udp group receiver
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <netdb.h>

#define BUFSIZE	2048

int main(int argc, char *argv[])
{
	int sockfd;
#if 0
	struct sockaddr_in addr;
#endif
	//socklen_t addrlen;
	char buf[BUFSIZE];
	ssize_t n;
	struct addrinfo hints, *res;
	int errcode;
	struct group_req greq;	

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;
	errcode = getaddrinfo(NULL, "12345", &hints, &res);
	if (errcode)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errcode));
		exit(EXIT_FAILURE);
	}

	/* 1. create an endpoint for communication */
	sockfd = socket(res->ai_family, res->ai_socktype, 0);
	if (sockfd < 0)
	{
		perror("socket: ");
		exit(EXIT_FAILURE);
	}

	/* 2. bind a name to a socket */
#if 0
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = INADDR_ANY;
	res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
#else
	errcode = bind(sockfd, res->ai_addr, res->ai_addrlen);
#endif
	if (errcode < 0)
	{
		perror("bind: ");
		exit(EXIT_FAILURE);
	}
	
	freeaddrinfo(res);

	fprintf(stdout, "listening...\n");
	fflush(stdout);
	
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	errcode = getaddrinfo("239.192.1.2", "12345", &hints, &res);
	if (errcode)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errcode));
		exit(EXIT_FAILURE);
	}
	
	memset(&greq, 0, sizeof(greq));	
	greq.gr_interface = 0;
	memcpy(&greq.gr_group, res->ai_addr, res->ai_addrlen);
	freeaddrinfo(res);

	if (setsockopt(sockfd, IPPROTO_IP, MCAST_JOIN_GROUP, (char *)&greq, sizeof(greq)))
	{
		perror("setsockopt: ");
		exit(EXIT_FAILURE);
	}

	memset(buf, 0, sizeof(buf));	
	n = recv(sockfd, buf, sizeof(buf), 0);
	write(fileno(stdout), buf, n);
	write(fileno(stdout), "\n", 1);

	close(sockfd);

	return 0;
}
