#include <stdio.h>
#include <unistd.h> /* for getopt */
#include <stdlib.h> /* for atoi */
#include <getopt.h>

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
		static struct option long_options[] = 
		{
			{"flags", required_argument, 0, 'f'},
			{"time", required_argument, 0, 't'},
			{0, 0, 0, 0}
		};
		int option_index = 0;

		opt = getopt_long(argc, argv, "f:t:", long_options, &option_index);
		if (opt == -1)
			break;

		this_optind = optind;
		printf("this_optind=%d\n", this_optind);

		printf("opt=\'%c\'\n", opt);
		switch (opt) {
			case 'f':
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
