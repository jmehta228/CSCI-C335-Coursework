#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	FILE *filePtr;
	if (argc < 2) {
                printf("Error: Incorrect number of arguments\n");
                exit(EXIT_FAILURE);
        }
	else if (strcmp(argv[1], "printf") == 0) {
		printf("You entered: %s\n", argv[2]);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(argv[1], "fprintf") == 0) {
		filePtr = fopen("print.txt", "a");
		fprintf(filePtr, "%s", argv[2]);
		fclose(filePtr);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(argv[1], "scanf") == 0) {
		char string[50];
		printf("Please enter your input: ");
		scanf("%49s", string);
		printf("You entered: %s\n", string);
		exit(EXIT_SUCCESS);
	}
	else {
		exit(EXIT_FAILURE);
	}
}
