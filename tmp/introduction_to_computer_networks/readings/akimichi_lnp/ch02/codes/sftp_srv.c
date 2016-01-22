/**
 * sftp_srv.c : receive a file transfered from a client
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE	65536

int main(int argc, char *argv[])
{
	struct addrinfo hints, *res;
	int errcode;
	int sockfd;
	int fd;
	struct sockaddr_in client;
	socklen_t addrlen;
	int clisock; /* a descriptor for the accepted socket */
	char buf[BUF_SIZE];
	int n;

	if (argc != 2) 
	{
		fprintf(stderr, "usage: %s outfilename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd < 0) 
	{
		perror("open: ");
		exit(EXIT_FAILURE);
	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if ((errcode = getaddrinfo(NULL, "12345", &hints, &res))) 
	{
		fprintf(stderr, "error %d: %s\n", errcode, gai_strerror(errcode));
		goto end_fd;
	}

	sockfd = socket(res->ai_family, res->ai_socktype, 0);
	if (sockfd < 0) 
	{
		perror("socket: ");
		goto end_fd;
	}

	if (bind(sockfd, res->ai_addr, res->ai_addrlen) < 0) 
	{
		perror("bind: ");
		goto end_sockfd;
	}

	freeaddrinfo(res);

	fprintf(stdout, "listening...\n");
	if (listen(sockfd, 1) < 0) 
	{
		perror("listen: ");
		goto end_sockfd;
	}

	addrlen = sizeof(socklen_t);
	if ((clisock = accept(sockfd, (struct sockaddr *)&client, &addrlen)) < 0) 
	{
		perror("accept: ");
		goto end_sockfd;
	}
	fprintf(stdout, "accepted...\n");

	while ((n = read(clisock, buf, sizeof(buf))) > 0) 
	{
		if (write(fd, buf, n) < 1)
		{
			perror("write: ");
			break;
		}
	}

end_sockfd:
	close(sockfd);
end_fd:
	close(fd);

	return 0;
}
