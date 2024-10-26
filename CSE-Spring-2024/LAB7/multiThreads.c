#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

typedef struct input_args {
	char *fileName;
	char *word;
	int count;
	int threadNum;
} input_args;

int wordCount(char *lineItem, char *word);

void* printCount(void *arg) {
	double threadTime = 0.0;
	clock_t threadBegin = clock();

	input_args *args = (input_args*)arg;
	FILE *filePtr;
	filePtr = fopen(args->fileName, "r");
	char *buffer;
	size_t bufferSize = 0;
	while (getline(&buffer, &bufferSize, filePtr) != -1) {
		args->count += wordCount(buffer, args->word);
		bufferSize = 0;
	}
	printf("%s Count: %d\n", args->word, args->count);

	clock_t threadEnd = clock();
	threadTime += (double)(threadEnd - threadBegin) / CLOCKS_PER_SEC;
	// printf("Time for thread %d: %lf\n", args->threadNum, threadTime);
	return NULL;
}

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
	double main_thread_time_spent = 0.0;
	clock_t mainThreadBegin = clock();

	// double thread_one_time_spent = 0.0;
	// double thread_two_time_spent = 0.0;

	if (argc != 5) {
		printf("Failure!\n");
		exit(EXIT_FAILURE);
	}
	else {
		pthread_t thread1;
		input_args t1;
		t1.fileName = argv[1];
		t1.word = argv[2];
		t1.count = 0;
		t1.threadNum = 1;
		pthread_create(&thread1, NULL, printCount, (void*)&t1);
//------------------------------------------------------------------------
		pthread_t thread2;
		input_args t2;
		t2.fileName = argv[3];
		t2.word = argv[4];
		t2.count = 0;
		t2.threadNum = 2;
                pthread_create(&thread2, NULL, printCount, (void*)&t2);
//------------------------------------------------------------------------
		// clock_t threadOneBegin = clock();
		pthread_join(thread1, NULL);
		// clock_t threadOneEnd = clock();
		// thread_one_time_spent += (double)(threadOneEnd - threadOneBegin) / CLOCKS_PER_SEC;

		// clock_t threadTwoBegin = clock();
                pthread_join(thread2, NULL);
		// clock_t threadTwoEnd = clock();
		// thread_two_time_spent += (double)(threadTwoEnd - threadTwoBegin) / CLOCKS_PER_SEC;
	}

	clock_t mainThreadEnd = clock();
	main_thread_time_spent += (double)(mainThreadEnd - mainThreadBegin) / CLOCKS_PER_SEC;

	// printf("\nMain thread time: %lf\n", main_thread_time_spent);

}
