#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/tiocl.h>

int main(	int argc, 
		char **argv
	)
{
	int fd;
	//char bytes[2] = {TIOCL_SETKMSGREDIRECT, 0};
	char bytes[2] = {11, 0};
	char ret = 0;

	if (argc == 2) {
		bytes[1] = atoi(argv[1]);
	} else {
		fprintf(stderr, "Usage: %s <number>\n", argv[0]);
		exit(1);
	}
	
	if (ioctl(STDOUT_FILENO, TIOCLINUX, bytes) < 0) {
		fprintf(stderr, "Fail to ioctl: %s\n", strerror(errno));
	}

	close(STDOUT_FILENO);

	return 0;
}
