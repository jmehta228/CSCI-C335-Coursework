#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Failure!\n");
		exit(EXIT_FAILURE);
	}
	else {
		int array[ASIZE]; 
		for (int i = 0; i < ASIZE; i++) {
			array[i] = i*atoi(argv[1]);
		}

                int childSum = 0;
                int parentSum = 0;

		int fd[2];
		pipe(fd);

		pid_t forkValue = fork();

		if (forkValue == -1) {
			printf("Fork failed\n");
			exit(EXIT_FAILURE);
		}
		else if (forkValue == 0) { // child process
			close(fd[1]);
			for (int i = 0; i < ASIZE / 2; i++) {
				childSum += array[i];
			}
			int tempParentSum = 0;
			read(fd[0], &tempParentSum, sizeof(int));
			close(fd[0]);
			// printf("Child sum = %d\nParents sum = %d\n\n", childSum, tempParentSum);
			printf("%d\n", tempParentSum + childSum);
		}
		else if (forkValue > 1) { // parent process
			close(fd[0]);
			int start = (ASIZE % 2 == 0) ? ASIZE / 2 : (ASIZE / 2) + 1;
			for (int i = start; i < ASIZE; i++) {
				parentSum += array[i];
			}
			// printf("PARENT SUM: %d\n", parentSum);
			write(fd[1], &parentSum, sizeof(int));
			wait(&forkValue);
		}
	}
	return 0;
}
