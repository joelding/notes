/* getip.c : get all ips on the system where this program runs.
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
	struct addrinfo hints, *res, *res0;
	int errcode;
	const char *service = "http";
	int sock;
	struct in_addr addr;
	char buf[16];

	if (argc != 2) {
		fprintf(stderr, "Usage: %s hostname\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_family = PF_UNSPEC;
	//if (getaddrinfo(argv[1], NULL, &hints, &res)) {
	if ((errcode = getaddrinfo(argv[1], service, &hints, &res0))) {
		//perror("getaddrinfo: ");
		fprintf(stderr, "error %d: %s\n", errcode, gai_strerror(errcode));
		exit(EXIT_FAILURE);
	}

	for (res = res0; res != NULL; res = res->ai_next) {
		sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (sock < 0) {
			fprintf(stderr, "Fail to create an endpoint\n");
			continue;
		}

		if (!connect(sock, res->ai_addr, res->ai_addrlen)) {
			addr.s_addr = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;
			inet_ntop(AF_INET, &addr, buf, sizeof(buf));
			fprintf(stdout, "Succeed to connect ip address: %s\n", buf);
			close(sock);
			continue;
		}

		fprintf(stdout, "Failed to connect ip address: %s\n", buf);

		break; 
	}

	freeaddrinfo(res0);

	if (!res) {
		fprintf(stderr, "Failed\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
