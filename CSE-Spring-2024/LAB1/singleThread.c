#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <unistd.h>


int wordCount(char *lineItem, char *word) {
	int count = 0;
	char *index = lineItem;

	while ((index = strstr(index, word)) != NULL) {
		count += 1;
		index += strlen(word);
	}

	return count;
}

int main(int argc, char *argv[]) {
	double time_spent = 0.0;
	clock_t begin = clock();

	if (argc < 4) {
		exit(EXIT_FAILURE);
	}
//--------------------------
	FILE *filePtr1;
	filePtr1 = fopen(argv[1], "r");
	int word1Count = 0;
	char *buffer1;
	size_t bufferSize1 = 0;

	if (filePtr1 == NULL) {
		puts("Unable to open\n");
		exit(EXIT_FAILURE);
	}
	else {
		while (getline(&buffer1, &bufferSize1, filePtr1) != -1) {
			word1Count += wordCount(buffer1, argv[2]);
			bufferSize1 = 0;
		}
	}
	fclose(filePtr1);
//--------------------------
	FILE *filePtr2;
	filePtr2 = fopen(argv[3], "r");
	int word2Count = 0;
	char *buffer2;
	size_t bufferSize2 = 0;

	if (filePtr2 == NULL) {
		puts("Unable to open\n");
		exit(EXIT_FAILURE);
	}
	else {
		while (getline(&buffer2, &bufferSize2, filePtr2) != -1) {
			word2Count += wordCount(buffer2, argv[4]);
			bufferSize2 = 0;
		}
	}
	fclose(filePtr2);
//--------------------------

//	printf("%d\n%d\n", word1Count, word2Count);
	printf("%d\n%d\n", word1Count, word2Count);

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
//	printf("The elapsed time is %f seconds", time_spent);

	return 0;
}
