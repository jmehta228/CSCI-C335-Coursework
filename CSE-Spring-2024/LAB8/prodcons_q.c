#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

char buffer[5];
sem_t reader;
sem_t writer;
sem_t mutex;

void *generateLowerCaseLetters(void *thread_id) {
	int *id = (int*)thread_id;
	sem_wait(&reader);
	for (int i = 0; i < 5; i++) {
		char c = ('a' + rand() % 26);
		buffer[i] = c;
		printf("writer ID: %d, char written: %c\n", *id, c);
	}
	sem_post(&writer);
	return NULL;
}

void *generateUpperCaseLetters(void *thread_id) {
	int *id = (int*)thread_id;
	sem_wait(&reader);
	for (int i = 0; i < 5; i++) {
		char c = ('A' + rand() % 26);
		buffer[i] = c;
		printf("writer ID: %d, char written: %c\n", *id, c);
	}
	sem_post(&writer);
	return NULL;
}

void *readLetters(void *thread_id) {
	int *id = (int*)thread_id;
	sem_wait(&writer);
	for (int i = 0; i < 5; i++) {	
		printf("reader ID: %d, char read: %c\n", *id, buffer[i]);
	}
	sem_post(&reader);
	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc != 1) {
		printf("Failure!\n");
		exit(EXIT_FAILURE);
	}
	(void)argv[0];
	pthread_t threads[8];
	int thread_ids[4] = {0, 1, 2, 3};

	sem_init(&reader, 2, 1);
	sem_init(&writer, 2, 0);
	
	pthread_create(&threads[0], NULL, generateLowerCaseLetters, (void*)&thread_ids[0]); // thread 1
	pthread_create(&threads[1], NULL, generateLowerCaseLetters, (void*)&thread_ids[1]); // thread 2

	pthread_create(&threads[2], NULL, generateUpperCaseLetters, (void*)&thread_ids[2]); // thread 3
	pthread_create(&threads[3], NULL, generateUpperCaseLetters, (void*)&thread_ids[3]); // thread 4
	
	pthread_create(&threads[4], NULL, readLetters, (void*)&thread_ids[0]); // thread 5
	pthread_create(&threads[5], NULL, readLetters, (void*)&thread_ids[1]); // thread 6
	pthread_create(&threads[6], NULL, readLetters, (void*)&thread_ids[2]); // thread 7
	pthread_create(&threads[7], NULL, readLetters, (void*)&thread_ids[3]); // thread 8
	
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
	pthread_join(threads[3], NULL);

	pthread_join(threads[4], NULL);
	pthread_join(threads[5], NULL);
	pthread_join(threads[6], NULL);
	pthread_join(threads[7], NULL);
	
	return 0;
}
