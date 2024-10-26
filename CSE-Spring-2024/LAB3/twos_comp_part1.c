#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("FAILURE\n");
		exit(EXIT_FAILURE);
	}
	else {
		int inputNumber = atoi(argv[1]);
		if (inputNumber >= -128 && inputNumber <= 127) { // in range
			char binaryString[] = "00000000";
		        if (inputNumber >= 0) { //zero/positive
                		for (int i = strlen(binaryString) - 1; i >= 0; i--) {
                        		if (inputNumber % 2 == 0) {
                                		binaryString[i] = '0';
                        		}
                        		else if (inputNumber % 2 != 0) {
                                		binaryString[i] = '1';
                        		}
                        		inputNumber = inputNumber / 2;
                		}
        		}
        		else { //negative
                		inputNumber = inputNumber * -1;
                		for (int i = strlen(binaryString) - 1; i >= 0; i--) {
                        		if (inputNumber % 2 == 0) {
                        		        binaryString[i] = '0';
                        		}
                        		else if (inputNumber % 2 != 0) {
                        		        binaryString[i] = '1';
                        		}
                        		inputNumber = inputNumber / 2;
                		}
//				printf("Binary string after *-1: %s\n", binaryString);
                		for (size_t k = 0; k < strlen(binaryString); k++) { // invert binary
                        		if (binaryString[k] == '0') {
                        		        binaryString[k] = '1';
                        		}
					else if (binaryString[k] == '1') {
                        	        	binaryString[k] = '0';
                        		}
                		}
//				printf("Binary string after inverting value: %s\n", binaryString);
				int intValue = strtol(binaryString, NULL, 2);
				intValue += 1;
				char newBinaryString[] = "00000000";
				for (int c = strlen(newBinaryString) - 1; c >= 0; c--/*haha*/) {
					if (intValue % 2 == 0) {
						newBinaryString[c] = '0';
					}
					else if (intValue % 2 != 0) {
						newBinaryString[c] = '1';
					}
					intValue = intValue / 2;
				}
//				printf("Binary string after adding 1 to integer/new binary string: %s\n", newBinaryString);
//				printf("%s\n", newBinaryString);
//				strcpy(binaryString, newBinaryString);
				for (size_t i = 0; i < strlen(newBinaryString); i++) {
					binaryString[i] = newBinaryString[i];
				}
			}
//			printf("Binary string after using for loop to replace newBinaryString to binaryString: %s\n", binaryString);
			printf("%s\n", binaryString);
		}
		else {
			printf("FAILURE\n");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
