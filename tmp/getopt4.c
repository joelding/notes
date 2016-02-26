#include <unistd.h>
#include <stdio.h>

int c;
char *filename;
extern char *optarg;
extern int optind, optopt, opterr;

int main(int argc, char *argv[])
{
	while ((c = getopt(argc, argv, ":abf:")) != -1) 
	{
		switch(c) 
		{
			case 'a':
				printf("a is set\n");
			        break;
	
	    		case 'b':
				printf("b is set\n");
				break;
			
		        case 'f':
			        filename = optarg;
			        printf("filename is %s\n", filename);
			        break;
			
			case ':':
				printf("-%c without filename\n", optopt);
				break;
				
			case '?':
			        printf("unknown arg %c\n", optopt);
			        break;
		}
	}

	return 0;
}
