/** exec.c: test execl, execlp, execle, execv, execvp, execvpe - execute a file
 */

#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid[2];
	int status;
	extern char **environ;
	char **p = environ;
	int i = 0;
	char *args[] = {
		"ls",
		"-al",
		NULL
	};

	/* command printenv */
	printf("extern char **environ = \n");
	while (p[i])
		printf("%s\n", p[i++]);

	pid[0] = fork();
	if (pid[0] == 0) {
		printf("[%d] $ ls -al\n", __LINE__);
		if (-1 == execlp("ls", "ls", "-al", NULL))
			printf("%s", strerror(errno));
	}

	printf("child %d spawned\n", pid[0]);

	pid[1] = fork();
	if (pid[1] == 0) {
		printf("[%d] $ ls -al\n", __LINE__);
		if (-1 == execvp("ls", args))
			printf("%s", strerror(errno));
	}
	printf("child %d spawned\n", pid[1]);

	printf("pid %d terminated\n", wait(&status));

	return 0;
}
