#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str[] = "abc\\\"def\\\"";
	int len, i;

	printf("%s\n", str);
	
	len = strlen(str);
	printf("len = %d\n", len);

	for (i = 0; i < len; ++i)
		printf("0x%02x ", str[i]);
	
	printf("\n");

	str[len - 1] = str[len - 2] = 0;
	printf("%s\n", str);

	return 0;
}
