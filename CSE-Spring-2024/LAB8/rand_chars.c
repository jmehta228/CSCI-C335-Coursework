#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void printLowerCase() {
	printf("%c\n", ('a' + rand() % 26));
}

void printUpperCase() {
	printf("%c\n", ('A' + rand() % 26));
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Failure!\n");
		exit(EXIT_FAILURE);
	}
	// char arg[] = argv[1];
	if (strcmp(argv[1], "-l") == 0) {
		for (int i = 0; i < 10; i++) {
			printLowerCase();
		}
	}
	else if (strcmp(argv[1], "-u") == 0) {
		for (int i = 0; i < 10; i++) {
			printUpperCase();
		}
	}
	else {
		printf("Failure!\n");
		exit(EXIT_FAILURE);
	}
}
