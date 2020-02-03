#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <time.h>
#include <math.h>

int status;


void print_current_time_with_s (void)
{
    time_t          s;  // Seconds
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);

    s  = spec.tv_sec;
   
    printf("Current time: %lld second since the Epoch\n", s);
}

void printLetter(const char* word, int i) {
	if (i >= 10)
		return;

	pid_t child_pid = fork();

	if (child_pid >= 0) {
		if (child_pid == 0) {
			printf("%c, pid is %d, \n", word[i], getpid());
			// print_current_time_with_s();
			// while(1) {
				sleep(rand() % 3 + 1);
			// }

			printLetter(word, i + 1);
		} else
			wait(&status);
	} else {
		printf("error in for for i is %d \n", i);
		exit(0);
	}
}

int main() {
	pid_t myPid; 

	char *word = {"helloworld"};
	// char word[10] = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};

	// for (int i = 0; i < 10; i++) {
	// 	printf("char is  %c \n ", word[i]);
	// }
	printLetter(word, 0);

	// pid_t child_pid = fork();

	// if (child_pid >= 0) {
	// 	if (child_pid == 0) {
	// 		printf("child process");
	// 		// char* cmd[] = {"./"}

	// 	}
	// 	else {
	// 		printf("parent process");
	// 	}
	// }


	// printf("my pid is %d \n", getpid());
	return 0;
}