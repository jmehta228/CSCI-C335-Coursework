#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
        if (argc != 3) {
                printf("FAILURE\n");
                exit(EXIT_FAILURE);
        }
	else {
		char binaryString[] = "00000000";
		strcpy(binaryString, argv[1]);
//		printf("%s\n", binaryString);
		if ((strcmp(argv[2], "unsigned") == 0)) { // check if positive
			if (strtol(binaryString, NULL, 2) <= 255 && strtol(binaryString, NULL, 2) >= 0) {
				printf("%ld\n", strtol(binaryString, NULL, 2));
			}
			else {
				printf("FAILURE\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(argv[2], "signed") == 0) { // check if negative
			if (strcmp("00000000", binaryString) == 0) {
				printf("0\n");
				exit(0);
			}
			if (strlen(binaryString) == 8) {
				for (size_t c = 0; c < strlen(binaryString); c++) { // inverting binaryString
					if (binaryString[c] == '0') {
						binaryString[c] = '1';
					}
					else if (binaryString[c] == '1') {
						binaryString[c] = '0';
					}
				}
				// further steps here
				int binaryStringToInt = strtol(binaryString, NULL, 2);
				binaryStringToInt += 1;
				binaryStringToInt *= -1;
				printf("%d\n", binaryStringToInt);
			}
			else {
				printf("FAILURE\n");
				exit(EXIT_FAILURE);
			}
		}
		else {
			printf("FAILURE\n");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
