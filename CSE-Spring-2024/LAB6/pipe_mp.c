#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		exit(EXIT_FAILURE);
	}
	else {
		int fd[2];
		pipe(fd);
		char bufferArr[16];
		
		int forkVal = fork();

		if (forkVal == 0) { // child
			read(fd[0], bufferArr, 16);
			printf("%s\n", bufferArr);
		}
		else if (forkVal > 0) { // parent
			write(fd[1], argv[1], 16);
			wait(&forkVal);
		}
	}
	return 0;
}
