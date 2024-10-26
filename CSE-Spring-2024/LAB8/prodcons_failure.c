#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int* array;

void* thread_function(void* arg) {
        int num = *((int*)arg);
        array = (int*)malloc(num * sizeof(int));
        for (int i = 0; i < num; i++) {
                array[i] = (rand() % (num + 1));
                printf("writer wrote: %d\n", array[i]);
        }
        return NULL;
}

int main(int argc, char *argv[]) {
        if (argc != 2) {
                printf("Failure!\n");
                exit(EXIT_FAILURE);
        }
	int n = atoi(argv[1]);
	if (n != 0) {
		pthread_t thread;
		pthread_create(&thread, NULL, thread_function, &n);
		pthread_join(thread, NULL);
		for (int c = 0; c < n; c++) {
                	printf("main read: %d\n", array[c]);
        	}
	}
	else {
		printf("Failure!\n");
		exit(EXIT_FAILURE);
	}
        return 0;
}
