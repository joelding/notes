#include <stdio.h>
#include <unistd.h> /* for getopt */
#include <stdlib.h> /* for atoi */

int main(int argc, char *argv[])
{
	int opt;
	int flags = 0;
	int nsecs = 0;
	int this_optind = optind ? optind : 1;

	printf("optind=%d\n", optind);
	printf("this_optind=%d\n\n", this_optind);
	while (1)
	{
		opt = getopt(argc, argv, "n:t:");
		if (opt == -1)
			break;

		this_optind = optind;
		printf("this_optind=%d\n", this_optind);

		printf("opt=\'%c\'\n", opt);
		switch (opt) {
			case 'n':
				flags = atoi(optarg);
				printf("flags=%d\n", flags);
				break;

			case 't':
//				nsecs = atoi(optarg); // This causes segmentation fault?!?
				nsecs = atoi(optarg);
				printf("nsecs=%d\n", nsecs);
				break;
			case '?':
				printf("usage:\n");
				break;
			default:
				printf("Unknown %c\n", opt);
				break;
		}
	}
	
	if (argc <= this_optind)	
	{
		printf("usage: \n");
		return 0;
	}


	return 0;
}
