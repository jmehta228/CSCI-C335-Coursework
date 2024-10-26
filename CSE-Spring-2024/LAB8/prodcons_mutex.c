#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int* array;

sem_t r_mutex;
sem_t w_mutex;

void* thread_function(void* arg) {
        int num = *((int*)arg);
        array = (int*)malloc(num * sizeof(int));
        for (int i = 0; i < num; i++) {
                array[i] = (rand() % (num + 1));
		sem_wait(&r_mutex);
                printf("writer wrote: %d\n", array[i]);
		sem_post(&w_mutex);
        }
        return NULL;
}

int main(int argc, char *argv[]) {
        if (argc != 2) {
                printf("Failure!\n");
                exit(EXIT_FAILURE);
        }
        int n = atoi(argv[1]);

        sem_init(&r_mutex, 2, 1);
        sem_init(&w_mutex, 2, 0);

        if (n != 0) {
                pthread_t thread;
                pthread_create(&thread, NULL, thread_function, &n);
                for (int c = 0; c < n; c++) {
			sem_wait(&w_mutex);
                        printf("main read: %d\n", array[c]);
			sem_post(&r_mutex);
                }
		pthread_join(thread, NULL);

        }
        else {
                printf("Failure!\n");
                exit(EXIT_FAILURE);
        }
        return 0;
}
