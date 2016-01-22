/**
 * sftp_cli.c : a client-side program transmitting a file 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 65536

int main(int argc, char *argv[])
{
	int fd;
	struct addrinfo hints, *res, *p;
	int errcode;
	int sockfd;
	char buf[BUF_SIZE];
	int n;

	if (argc != 3) 
	{
		fprintf(stderr, "usage: %s hostname infilename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[2], O_RDONLY);
	if (fd < 0) 
	{
		perror("open: ");
		exit(EXIT_FAILURE);
	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if ((errcode = getaddrinfo(argv[1], "12345", &hints, &res))) 
	{
		fprintf(stderr, "error %d: %s\n", errcode, gai_strerror(errcode));
		goto end_fd;
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
		goto end_fd;
	}

	while ((n = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (write(sockfd, buf, n) < 1)
		{
			perror("write: ");
			break;
		}
	}

	close(sockfd);
end_fd:
	close(fd);

	return 0;
}
