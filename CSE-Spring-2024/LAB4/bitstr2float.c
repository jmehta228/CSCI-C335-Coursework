#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("FAILURE\n");
		exit(EXIT_FAILURE);
	}
	else {
		char floatingPointBinaryString[strlen(argv[1])];
		strcpy(floatingPointBinaryString, argv[1]);

		if (strcmp(floatingPointBinaryString, "00000000000000000000000000000000") == 0) {
			printf("Sign: 0\nExponent: 0\nMantissa: 0\nNumber: 0\n");
			exit(0);
		}

		for (size_t i = 0; i < strlen(floatingPointBinaryString); i++) {
			for (char ch = 'A'; ch <= 'Z'; ch++) {
				if (floatingPointBinaryString[i] == ch) {
					puts("Incorrect input argument");
					exit(EXIT_FAILURE);
				}
			}
		}

		char signChar = floatingPointBinaryString[0];
		int sign = signChar - '0';
		printf("Sign: %d\n", sign); // printing sign

		char expBinaryString[8];
		for (int i = 1; i < 9; i++) {
			expBinaryString[i - 1] = floatingPointBinaryString[i];
		}
		int expBinaryNumber = strtol(expBinaryString, NULL, 2);

		printf("Exponent: %d\n", expBinaryNumber); // printing exponent

		char mantissaBinaryString[24];
		strncpy(mantissaBinaryString, floatingPointBinaryString + strlen(floatingPointBinaryString) - 23, 23);
		mantissaBinaryString[23] = '\0';
		double mantissaValue = 0.0;
		for (size_t k = 0; k < strlen(mantissaBinaryString); k++) {
			if (mantissaBinaryString[k] == '1') {
				mantissaValue += (1 / pow(2, k + 1)) * 1.0;
			}
			else if (mantissaBinaryString[k] == '0') {
				mantissaValue += (1 / pow(2, k + 1)) * 0.0;
			}
			else {
				exit(EXIT_FAILURE);
			}
		}

		if (expBinaryNumber != 0) {
			mantissaValue += 1.0;
			printf("Mantissa: %.17g\n", mantissaValue); // printing mantissa
			int EValue = expBinaryNumber - 127;
			printf("Number: %.7g\n", ((pow(-1, sign)) * (mantissaValue) * (pow(2, EValue)))); // printing number
		}
		else {
			printf("Mantissa: %.17g\n", mantissaValue); // printing mantissa
			int EValue = 1 - 127;
			printf("Number: %.7g\n", ((pow(-1, sign)) * (mantissaValue) * (pow(2, EValue)))); // printing number
		}
	}
	return 0;
}
