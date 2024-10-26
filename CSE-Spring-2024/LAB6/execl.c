#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		exit(EXIT_FAILURE);
	}
	else {
		char string[100] = "/bin/";
		for (size_t i = 0; i < strlen(argv[1]); i++) {
			char *argv1 = argv[1];
			string[i + 5] = argv1[i];
		}
		execl(string, argv[1], argv[2], NULL);
	}

	return 0;
}
