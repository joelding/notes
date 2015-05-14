#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *p = NULL;
	const char haystack[] = "EP9142_Avermedia_14081916";
	const char needle[] = "Avermedia";
	const char needle2[] = "Avm";

	p = strstr(haystack, needle);
	printf("Found %s%s\n", p ? "" : "no ", needle);

	p = strstr(haystack, needle2);
	printf("Found %s%s\n", p ? "" : "no ", needle2);

	return 0;
}
