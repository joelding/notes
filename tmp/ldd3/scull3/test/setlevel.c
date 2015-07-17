#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
//#define __LIBRARY__
//#include <linux/unistd.h>
#include <sys/klog.h>

int main (	int argc,
		char **argv
	)
{
	int level;

	if (argc != 2) {
		printf("Usage: %s <level>\n", argv[0]);
		exit(1);
	}

	level = atoi(argv[1]);

	//if (syslog(8, NULL, level) < 0) {
	if (klogctl(8, NULL, level) < 0) {
		printf("%s\n", strerror(errno));
	}

	return 0;
}
