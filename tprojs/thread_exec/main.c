#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

#define dbg(fmt, arg...) do { fprintf(stdout, "%s[%s@%d] " fmt, __func__, __FILE__, __LINE__, ##arg); fflush(stdout); } while (0)
#define err(fmt, arg...) do { fprintf(stderr, "!%s[%s@%d] " fmt, __func__, __FILE__, __LINE__, ##arg); fflush(stderr); } while (0)

//static	int status = 0;

static void *start_routine(void *arg)
{
//	int status = 0;
	void *status = NULL;

	status = malloc(sizeof(int));

	do {
		if (!status) {
			err("Fail malloc\n");
			break;
		}

		*(int *)status = 50;

		dbg("\n");
	} while (0);

	//pthread_exit((void *)&status);
	pthread_exit(status);

	return NULL;
}

int main(int argc, char *argv[])
{
	int ret = -1;
	int *status = NULL;
	pthread_t thread;
	void *arg = NULL;

	dbg("\n");

	ret = pthread_create(&thread, NULL, start_routine, arg);
	if (ret) {
		fprintf(stderr, "%s\n", strerror(errno));
	}

	ret = pthread_join(thread, (void **)&status);
	if (ret) {
		fprintf(stderr, "%s\n", strerror(errno));
	}

	dbg("status = %d\n", *status);
	if (status)
		free(status);

	return 0;
}
