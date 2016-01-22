/* ssrv3.c: simple TCP server. getaddrinfo before bind.
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
	int sockfd; /* a file descriptor for the new socket */
	struct sockaddr_in addr;
	socklen_t addrlen;
	int asock; /* a descriptor for the accepted socket */
	struct addrinfo hints, *res = NULL;
	int eno;

	memset(&hints, 0, sizeof(struct addrinfo));
	/* 
		If  the  AI_PASSIVE  flag  is  specified in hints.ai_flags, and node is
		NULL,  then  the  returned  socket  addresses  will  be  suitable   for
		bind(2)ing  a  socket  that  will  accept(2) connections.  The returned
		socket address will contain the "wildcard address" (INADDR_ANY for IPv4
		addresses, IN6ADDR_ANY_INIT for IPv6 address).  The wildcard address is
		used by applications (typically servers) that intend to accept  connec‐
		tions  on  any  of the hosts's network addresses.  If node is not NULL,
		then the AI_PASSIVE flag is ignored.
	*/

	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	if ((eno = getaddrinfo(NULL, "12345", &hints, &res))) {
		fprintf(stderr, "%s@%d %s", __FILE__, __LINE__, gai_strerror(eno));
		exit(EXIT_FAILURE);
	}

	/* 1. create an endpoint for communication */
	sockfd = socket(res->ai_family, res->ai_socktype, 0); /* IPv4 TCP */
	if (sockfd < 0) {
		perror("socket: ");
		exit(EXIT_FAILURE);
	}

#if 0
	/* 2. set IP address and port */
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = INADDR_ANY; /* local host address */
	
	/* 3. assign a name to a socket */
	bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
#else
	if (bind(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
		perror("bind: ");
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(res);
#endif

	/* 4. listen for connections on a socket */
	fprintf(stdout, "listening...\n");
	if (listen(sockfd, 1) < 0) {
		perror("listen: ");
		exit(EXIT_FAILURE);
	}

	/* 5. accept a connection on a socket */
	addrlen = sizeof(socklen_t);
	if ((asock = accept(sockfd, (struct sockaddr *)&addr, &addrlen)) < 0) {
		perror("accept: ");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "accepted...\n");

	/* 6. start communication */
	write(asock, "HELLO", 5);

	close(asock);

	close(sockfd);

	return 0;
}
