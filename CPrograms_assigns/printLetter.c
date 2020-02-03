#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv) {	
	char* word = argv[1];
	int i = atoi(argv[2]);
	int n = atoi(argv[3]);

	if (i < n) {
		printf("%c, pid is %d, \n", word[i], getpid());
		char* cmd[] = {"./printLetter", word, argv[2] + 1, argv[3], NULL};
		return execv(cmd[0], cmd);
	}
	return 0;
}