#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *printA() {
	sem_wait(&semaphore);
	printf("A\n");
	return NULL;
}

void *printB() {
	sem_wait(&semaphore);
	printf("B\n");
	return NULL;
}

void *printC() {
	sem_wait(&semaphore);
	printf("C\n");
	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc != 1) {
		printf("Failure!\n");
		exit(EXIT_FAILURE);
	}
	(void)argv[0];
	sem_init(&semaphore, 0, 2);
	pthread_t threads[3];
	pthread_create(&threads[0], NULL, printA, NULL);
	pthread_create(&threads[1], NULL, printB, NULL);
	pthread_create(&threads[2], NULL, printC, NULL);

	// FIX for code issue sem_post(&semaphore);
	sem_post(&semaphore);

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);

	return 0;
}
