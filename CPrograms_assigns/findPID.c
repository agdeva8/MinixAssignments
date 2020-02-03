#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t myPID;

	myPID = getpid();

	printf("my pid is %d \n", myPID);
	printf("my parent pid is %d \n" , getppid());

	return 0;
}
