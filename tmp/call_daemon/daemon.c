#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(	int argc,
		char **argv[]
	)
{
	pid_t pid, sid;
	
	/* Fork off the parent process */
	pid = fork();
	if (pid < 0) {
		/* Log failure (use syslog if possible) */
		exit(EXIT_FAILURE);
	}
		        
	/* If we got a good PID, then we can exit the parent process. */
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}
	
	/* Change the file mode mask */
	umask(0);
	

	/* Open any logs here */  
	setlogmask(LOG_UPTO(LOG_DEBUG));
	openlog(NULL, LOG_PID | LOG_NDELAY, LOG_DAEMON);

	sid = setsid();	
	if (sid < 0) {
		/* Log the failure */
		exit(EXIT_FAILURE);
	}

	/* Change the current working directory */
	if ((chdir("/")) < 0) {
		/* Log the failure */
		exit(EXIT_FAILURE);
	}

	/* Close out the standard file descriptors */
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	/* Daemon-specific initialization goes here */
	syslog(LOG_DEBUG, "line %d started\n", __LINE__);

	/* The Big Loop */
	while (1) {
		/* Do some task here ... */
		syslog(LOG_DEBUG, "line %d\n", __LINE__);
		sleep(30); /* wait 30 seconds */
	}

	closelog();

	exit(EXIT_SUCCESS);
}
