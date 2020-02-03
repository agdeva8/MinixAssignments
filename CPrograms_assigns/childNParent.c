#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
// #include <strerror.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	pid_t childPid;

	int status; 
	int local = 0;

	childPid = fork();

	if (childPid >= 0) {
		if (childPid == 0) {
			printf("child process \n");

			printf("my pid %d, and my parent pid is %d \n" , getpid(), getppid());

			// char *cmd[] = {"ls", NULL};
			// return printf("execv status is %d \n ", execv("/usr/bin/",cmd));
			 char *args[]={"/bin/ls", "-a", NULL}; 
			if ( execv( args[0], args))
			{
			    printf("execv failed with error %d %s\n",errno,strerror(errno));
			}

			 // call whoami command
		}
		else {
			printf("parent process \n");
			pid_t child_pid = wait(&status);
			printf("my pid is %d and my child pid is %d \n", getpid(), child_pid);
			printf("child exit code is %d \n", WEXITSTATUS(status));
			printf("parent says bye \n");
		}
	}
	else {
		perror("error in fork");
		exit(0);
	}
}
