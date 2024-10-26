#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		exit(EXIT_FAILURE);
	}
	else {
		int arr[2];
		pipe(arr);
		char bufferArr[16];

		write(arr[1], argv[1], 16);
		write(arr[1], argv[2], 16);

		for (int i = 0; i < 2; i++) {
			read(arr[0], bufferArr, 16);
			printf("%s\n", bufferArr);
		}
	}
	return 0;
}
