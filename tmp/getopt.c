#include <stdio.h>
#include <unistd.h> /* for getopt */
#include <stdlib.h> /* for atoi */

int main(int argc, char *argv[])
{
	int opt;
	int flags = 0;
	int nsecs = 0;

	while ((opt = getopt(argc, argv, "nt")) != -1) {
		printf("opt=%c\n", opt);
		switch (opt) {
			case 'n':
				flags = 1;
				break;

			case 't':
//				nsecs = atoi(optarg); // This causes segmentation fault?!?
				nsecs = atoi(argv[optind]);
				break;

			case '?':
			case ':':
			default:
				printf("Unknown %c\n", opt);
				break;
		}
	}
				
	printf("flags=%d\n", flags);
	printf("nsecs=%d\n", nsecs);

	return 0;
}
