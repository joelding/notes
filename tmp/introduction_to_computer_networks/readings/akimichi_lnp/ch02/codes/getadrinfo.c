/* getadrinfo.c : practicing getaddrinfo/gethostbyname
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	struct addrinfo hints, *res;
	struct in_addr addr;
	char buf[16];
	int errcode;
	
	if (argc != 2) {
		fprintf(stderr, "usage: %s hostname\n", argv[0]);
		return 1;
	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_family = AF_INET;
	//if (getaddrinfo(argv[1], NULL, &hints, &res)) {
	if ((errcode = getaddrinfo(argv[1], NULL, &hints, &res))) {
		//perror("getaddrinfo: ");
		fprintf(stderr, "error %d: %s\n", errcode, gai_strerror(errcode));
		exit(EXIT_FAILURE);
	}

	addr.s_addr = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;
	inet_ntop(AF_INET, &addr, buf, sizeof(buf));
	fprintf(stdout, "ip address : %s\n", buf);
	freeaddrinfo(res);

	return 0;
}
