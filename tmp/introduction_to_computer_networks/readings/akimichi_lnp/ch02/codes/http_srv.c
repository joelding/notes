/**
 * http_srv.c : http server programs 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in caddr; /* client address */
	socklen_t len;
	struct addrinfo hints, *res = NULL;
	int errcode;
	int yes = 1;
	char buf[2048], inbuf[2048];
	int csock;
	int n;
	
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	if ((errcode = getaddrinfo(NULL, "12345", &hints, &res))) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, gai_strerror(errcode));
		exit(EXIT_FAILURE);
	}

	sockfd = socket(res->ai_family, res->ai_socktype, 0); 
	if (sockfd < 0) {
		perror("socket: ");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(sockfd, SOL_SOCKET,  SO_REUSEADDR, (const char *)&yes, sizeof(yes)) < 0)
	{
		perror("setsockopt: ");
		exit(EXIT_FAILURE);
	}

	if (bind(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
		perror("bind: ");
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(res);

	fprintf(stdout, "listening...\n");
	if (listen(sockfd, 1) < 0) {
		perror("listen: ");
		exit(EXIT_FAILURE);
	}

	snprintf(buf, sizeof(buf),
		"HTTP/1.0i 200 OK\r\n"
		"Content-Length: 20\r\n"
		"Content-Type: test/html\r\n"
		"\r\n"
		"HELLO\r\n");

	while (1)
	{	
		len = sizeof(socklen_t);
		if ((csock = accept(sockfd, (struct sockaddr *)&caddr, &len)) < 0) {
			perror("accept: ");
			exit(EXIT_FAILURE);
		}

		fprintf(stdout, "accepted...\n");

		n = read(csock, inbuf, sizeof(inbuf));
		write(fileno(stdout), inbuf, n);
		write(csock, buf, strlen(buf));
		close(csock);
	}


	return 0;
}
