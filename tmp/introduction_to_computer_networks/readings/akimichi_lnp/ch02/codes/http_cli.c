/**
 * http_cli.c : http client program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	struct addrinfo hints, *res, *p;
	int sockfd;
	char buf[32];
	int errcode;
	int n;

	if (argc != 2) 
	{
		fprintf(stderr, "usage: %s http_server\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	//if ((errcode = getaddrinfo(argv[1], "http", &hints, &res))) 
	if ((errcode = getaddrinfo(argv[1], "12345", &hints, &res))) 
	{
		fprintf(stderr, "error %d: %s\n", errcode, gai_strerror(errcode));
		goto end_sockfd;
	}

	for (p = res; p != NULL; p = p->ai_next)
	{
		sockfd = socket(p->ai_family, p->ai_socktype, res->ai_protocol);
		if (sockfd < 0)
		{
			perror("socket: ");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen))
		{
			close(sockfd);
			continue;
		}

		break;
	}

	freeaddrinfo(res);
	if (!p)
	{
		fprintf(stderr, "Fail to connect\n");
		goto end_sockfd;
	}

	snprintf(buf, sizeof(buf), "GET / HTTP/1.0\r\n\r\n");

	n = write(sockfd, buf, strlen(buf));
	if (n < 0)
	{
		perror("write: ");
		goto end_sockfd;
	}

	while ((n = read(sockfd, buf, sizeof(buf))) > 0) 
	{
		if (n < 0)
		{
			perror("read: ");
			break;
		}

		write(fileno(stdout), buf, n);
	}

end_sockfd:
	close(sockfd);

	return 0;
}
