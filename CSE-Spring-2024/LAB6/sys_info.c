#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_LENGTH 32

int main(int argc, char* argv[]) {
	if (argc != 3) {
		exit(EXIT_FAILURE);
	}
	else {
		int fd[2];

		if (pipe(fd) == -1) {
			exit(EXIT_FAILURE);
		}

		int forkVal = fork();

		if (forkVal == -1) {
			exit(EXIT_FAILURE);
		}
		else if (forkVal == 0) { // child
			char binaryName[BUFFER_LENGTH];
			char arg[BUFFER_LENGTH];
			
			read(fd[0], binaryName, BUFFER_LENGTH);
			read(fd[0], arg, BUFFER_LENGTH);

			char beginning[32] = "/bin/";
			if (strstr(binaryName, beginning) != NULL) { // contains
				execl(binaryName, binaryName, arg, NULL);
			}
			else { // does not contain
				for (size_t i = 0; i < strlen(argv[1]); i++) {
					char *bn = argv[1];
					beginning[i + 5] = bn[i];
				}
				execl(beginning, argv[1], arg, NULL);
			}
		}
		else if (forkVal > 0) { // parent
			write(fd[1], argv[1], BUFFER_LENGTH);
			write(fd[1], argv[2], BUFFER_LENGTH);
			wait(&forkVal);
		}
	}
	return 0;
}
