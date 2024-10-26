#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int globalVar;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		exit(EXIT_FAILURE);
	}
	else {
		globalVar = atoi(argv[1]);
		int forkVal = fork();
		if (forkVal == -1) {
			printf("Fork failed\n");
			exit(EXIT_FAILURE);
		}
		else if (forkVal == 0) {
			globalVar -= 1;
			printf("Hello World\n");
			printf("Child: %d\n", globalVar);
		}
		else {
			globalVar += 1;
			printf("Hello World\n");
			printf("Parent: %d\n", globalVar);
		}
	}
	return 0;
}
