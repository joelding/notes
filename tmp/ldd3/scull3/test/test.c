#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>

#define DEV "/dev/scull2"

int main(int argc, char *argv[])
{
	int fd = 0;

	if ((fd = open(DEV, O_RDWR)) < 0) {
		printf("Fail to open: %s\n", DEV);
		exit(EXIT_FAILURE);
	}

	close(fd);

	return 0;
}
