#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

#ifndef ASIZE
	#define ASIZE 1000
#endif

#ifndef NTHREADS
	#define NTHREADS 2
#endif

int counterVar = ASIZE / NTHREADS;
int globalSum = 0;

typedef struct {
	int *arr;
	int threadNumber;
} threadInfo;

void *calculateSum(void *arg) {
	threadInfo *args = (threadInfo*)arg;
	int *array = args->arr;
	int tn = args->threadNumber;
	int sum = 0;
	for (int i = tn * counterVar; i < (tn + 1) * counterVar; i++) {
		sum += array[i];
	}
	globalSum += sum;
	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Failure!\n");
		exit(EXIT_FAILURE);
	}
	int array[ASIZE];
	for (int i = 0; i < ASIZE; i++) {
		array[i] = i*atoi(argv[1]);
	}

	pthread_t threads[NTHREADS];

	for (int i = 0; i < NTHREADS; i++) {
		int num = i;
		threadInfo TI = {array, num};
		pthread_create(&threads[i], NULL, calculateSum, (void*)&TI);
		pthread_join(threads[i], NULL);
	}

	printf("%d\n", globalSum);

	return 0;
}
