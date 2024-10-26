#include <stdio.h>
#include <time.h>
#define SZ 50000

int A[SZ][SZ];

int main(void) {
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			A[i][j] = i * j;
		}
	}

	double timeSpent = 0.0;
	clock_t begin = clock();
	for (int i = 0; i < SZ; i++) {
		for (int j = 1; j < SZ; j++) {
			A[i][j] = (A[i][j - 1] + A[i][j]) / 2;
		}
	}
	clock_t end = clock();
	timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent: %f\n", timeSpent);

	return 0;
}
