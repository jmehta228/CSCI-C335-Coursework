#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct input_args {
	char *a;
	int b;
} input_args;

void *printStr(void* arg) {
	input_args *args = (input_args*)arg;
	printf("Concat String: %s\n", args->a);
	return NULL;
}

void *printCount(void *arg) {
	input_args *args = (input_args*)arg;
	printf("Count: %d\n", args->b);
	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Failure!\n");
		exit(EXIT_FAILURE);
	}
	else {
		pthread_t thread1;
		input_args t1;
		char *str1 = malloc(strlen(argv[1]) + 1);
		strcpy(str1, argv[1]);
		
		char str2[] = " Example";
		strcat(str1, str2);
		t1.a = str1;
		pthread_create(&thread1, NULL, printStr, (void*)&t1);
		pthread_join(thread1, NULL);

		pthread_t thread2;
		input_args t2;
		t2.b = atoi(argv[2]) + INCCNT;
		pthread_create(&thread2, NULL, printCount, (void*)&t2);
		pthread_join(thread2, NULL);
	}
	return 0;
}
