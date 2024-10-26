#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	double time_spent = 0.0;
	clock_t begin = clock();

	if (argc < 2) {
		exit(EXIT_FAILURE);
	}
	FILE *filePtr;
	filePtr = fopen(argv[1], "r");
	char line[4096];
	int count = 0;
	if (filePtr == NULL) {
		printf("Unable to open file!\n");
		exit(EXIT_FAILURE);
	}
	else {
		while (!feof(filePtr)) {
			fgets(line, 4096, filePtr);
//			count += containsWord(line, argv[2]);
			if (strstr(line, argv[2]) != NULL) {
				count += 1;
			}
		}
		fclose(filePtr);
	}
	printf("%d", count);

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

//	printf("\nThe elapsed time is %f seconds\n", time_spent);
	return 0;
}
