#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		puts("No input given");
		exit(EXIT_FAILURE);
	}
	else {
		char binaryString[] = "00000000000000000000000000000000";
		double inputFloat = atof(argv[1]);
		int wholeNumber;
		double decimalValue;
		wholeNumber = inputFloat;
		decimalValue = inputFloat - wholeNumber;
		// printf("Float: %f\nWhole Number: %d\nDecimal Value: %f\n", inputFloat, wholeNumber, decimalValue);
		char signBit = '0';
		if (inputFloat < 0) {
			signBit = '1';
		}
		else {
			signBit = '0';
		}
		binaryString[0] = signBit;
		int bias = 127;
		// printf("\nbinaryString: %s\n", binaryString);
		if (wholeNumber > 0) { // postive whole number
			if (decimalValue == 0.0) { // no decimal
				// printf("Number: %d\n", wholeNumber);
				int tempNumber = wholeNumber;
				if (tempNumber <= 255 && tempNumber >= 1) {
					char wholeNumberBinaryString[] = "00000000";
					size_t len1 = strlen(wholeNumberBinaryString);
					for (int i = len1 - 1; i >= 0; i--) {
						if (tempNumber % 2 == 0) {
							wholeNumberBinaryString[i] = '0';
						}
						else if (tempNumber % 2 != 0) {
							wholeNumberBinaryString[i] = '1';
						}
						tempNumber = tempNumber / 2;
					}
					// printf("8 bit binary string: %s\n", wholeNumberBinaryString);
					char expBinaryString[] = "0000000";
					size_t len2 = strlen(expBinaryString);
					for (int i = len2 - 1; i >= 0; i--) {
						expBinaryString[i] = wholeNumberBinaryString[i + 1];
					}
					// printf("Exp bin string: %s\n", expBinaryString);

					// int expBinStrToInt = strtol(expBinaryString, NULL, 2);
					// printf("expBinStrToInt: %d\n", expBinStrToInt);


					int biasPlusOneTwoSeven = bias + 7;
					char biasBinaryString[] = "00000000";
					size_t len3 = strlen(biasBinaryString);
					for (int i = len3 - 1; i >= 0; i--) {
						if (biasPlusOneTwoSeven % 2 == 0) {
							biasBinaryString[i] = '0';
						}
						else if (biasPlusOneTwoSeven % 2 != 0) {
							biasBinaryString[i] = '1';
						}
						biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
					}
					// printf("biasBinaryString: %s\n", biasBinaryString);
					
					for (size_t i = 0; i < strlen(biasBinaryString); i++) {
						binaryString[i + 1] = biasBinaryString[i];
					}
					for (size_t k = 0; k < strlen(expBinaryString); k++) {
						binaryString[k + 9] = expBinaryString[k];
					}
					printf("%s\n", binaryString);
				}
				else if (tempNumber >= 256 && tempNumber <= 511) {
					char wholeNumberBinaryString[] = "000000000";
					size_t length = strlen(wholeNumberBinaryString);
                                        for (int i = length - 1; i >= 0; i--) {
                                                if (tempNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (tempNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                tempNumber = tempNumber / 2;
                                        }
					// printf("9 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "00000000";
					size_t len5 = strlen(expBinaryString);
                                        for (int i = len5 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 8;
                                        char biasBinaryString[] = "00000000";
					size_t len6 = strlen(biasBinaryString);
                                        for (int i = len6 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);
					
					for (size_t i = 0; i < strlen(biasBinaryString); i++) {
						binaryString[i + 1] = biasBinaryString[i];
					}
					for (size_t k = 0; k < strlen(expBinaryString); k++) {
						binaryString[k + 9] = expBinaryString[k];
					}
					printf("%s\n", binaryString);
				}
				else if (tempNumber >= 512 && tempNumber <= 1023) {
					char wholeNumberBinaryString[] = "0000000000";
					size_t len7 = strlen(wholeNumberBinaryString);
                                        for (int i = len7 - 1; i >= 0; i--) {
                                                if (tempNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (tempNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                tempNumber = tempNumber / 2;
                                        }
                                        // printf("10 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "000000000";
					size_t len8 = strlen(expBinaryString);
                                        for (int i = len8 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 9;
                                        char biasBinaryString[] = "00000000";
					size_t len9 = strlen(biasBinaryString);
                                        for (int i = len9 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);

                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (tempNumber >= 1024 && tempNumber <= 2047) {
					char wholeNumberBinaryString[] = "00000000000";
					size_t len10 = strlen(wholeNumberBinaryString);
                                        for (int i = len10 - 1; i >= 0; i--) {
                                                if (tempNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (tempNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                tempNumber = tempNumber / 2;
                                        }
					// printf("11 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "0000000000";
					size_t lenlen = strlen(expBinaryString);
                                        for (int i = lenlen - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 10;
                                        char biasBinaryString[] = "00000000";
					size_t len11 = strlen(biasBinaryString);
                                        for (int i = len11 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);
                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (tempNumber >= 2048 && tempNumber <= 4096) {
					char wholeNumberBinaryString[] = "000000000000";
					size_t len11 = strlen(wholeNumberBinaryString);
                                        for (int i = len11 - 1; i >= 0; i--) {
                                                if (tempNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (tempNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                tempNumber = tempNumber / 2;
                                	}
					// printf("12 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "00000000000";
					size_t len12 = strlen(expBinaryString);
                                        for (int i = len12 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 11;
                                        char biasBinaryString[] = "00000000";
					size_t len13 = strlen(biasBinaryString);
                                        for (int i = len13 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);
                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        printf("%s\n", binaryString);
				}
			}
			else if (decimalValue > 0.0) { // ex: 1.5 --> dec: 0.5
				int tempNumber = wholeNumber;
				if (tempNumber <= 255 && tempNumber >= 1) {
					char wholeNumberBinaryString[] = "00000000";
					size_t len1 = strlen(wholeNumberBinaryString);
					for (int i = len1 - 1; i >= 0; i--) {
						if (tempNumber % 2 == 0) {
							wholeNumberBinaryString[i] = '0';
						}
						else if (tempNumber % 2 != 0) {
							wholeNumberBinaryString[i] = '1';
						}
						tempNumber = tempNumber / 2;
					}
					// printf("8 bit binary string: %s\n", wholeNumberBinaryString);
					char expBinaryString[] = "0000000";
					size_t len2 = strlen(expBinaryString);
					for (int i = len2 - 1; i >= 0; i--) {
						expBinaryString[i] = wholeNumberBinaryString[i + 1];
					}
					// printf("Exp bin string: %s\n", expBinaryString);

					// int expBinStrToInt = strtol(expBinaryString, NULL, 2);
					// printf("expBinStrToInt: %d\n", expBinStrToInt);


					int biasPlusOneTwoSeven = bias + 7;
					char biasBinaryString[] = "00000000";
					size_t len3 = strlen(biasBinaryString);
					for (int i = len3 - 1; i >= 0; i--) {
						if (biasPlusOneTwoSeven % 2 == 0) {
							biasBinaryString[i] = '0';
						}
						else if (biasPlusOneTwoSeven % 2 != 0) {
							biasBinaryString[i] = '1';
						}
						biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
					}
					// printf("biasBinaryString: %s\n", biasBinaryString);

					for (size_t i = 0; i < strlen(biasBinaryString); i++) {
						binaryString[i + 1] = biasBinaryString[i];
					}
					for (size_t k = 0; k < strlen(expBinaryString); k++) {
						binaryString[k + 9] = expBinaryString[k];
					}
					// printf("%s\n", binaryString);
					


					double posDecVal = decimalValue;
					char decBinString[] = "0000000000000000";
					int c = 0;
					while (c < 16) {
						posDecVal *= 2;
						decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
						posDecVal = posDecVal - (int)posDecVal;
					}
					for (size_t i = 0; i < strlen(decBinString); i++) {
						binaryString[i + 16] = decBinString[i];
					}
					printf("%s\n", binaryString);
				}
				else if (tempNumber >= 256 && tempNumber <= 511) {
					char wholeNumberBinaryString[] = "000000000";
					size_t length = strlen(wholeNumberBinaryString);
                                        for (int i = length - 1; i >= 0; i--) {
                                                if (tempNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (tempNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                tempNumber = tempNumber / 2;
                                        }
					// printf("9 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "00000000";
					size_t len5 = strlen(expBinaryString);
                                        for (int i = len5 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 8;
                                        char biasBinaryString[] = "00000000";
					size_t len6 = strlen(biasBinaryString);
                                        for (int i = len6 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);

					for (size_t i = 0; i < strlen(biasBinaryString); i++) {
						binaryString[i + 1] = biasBinaryString[i];
					}
					for (size_t k = 0; k < strlen(expBinaryString); k++) {
						binaryString[k + 9] = expBinaryString[k];
					}
					// printf("%s\n", binaryString);


                                        double posDecVal = decimalValue;
                                        char decBinString[] = "000000000000000";
                                        int c = 0;
                                        while (c < 15) {
                                                posDecVal *= 2;
                                                decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
                                                posDecVal = posDecVal - (int)posDecVal;
                                        }
                                        for (size_t i = 0; i < strlen(decBinString); i++) {
                                                binaryString[i + 17] = decBinString[i];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (tempNumber >= 512 && tempNumber <= 1023) {
					char wholeNumberBinaryString[] = "0000000000";
					size_t len7 = strlen(wholeNumberBinaryString);
                                        for (int i = len7 - 1; i >= 0; i--) {
                                                if (tempNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (tempNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                tempNumber = tempNumber / 2;
                                        }
                                        // printf("10 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "000000000";
					size_t len8 = strlen(expBinaryString);
                                        for (int i = len8 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 9;
                                        char biasBinaryString[] = "00000000";
					size_t len9 = strlen(biasBinaryString);
                                        for (int i = len9 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);

                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        // printf("%s\n", binaryString);
                                        double posDecVal = decimalValue;
                                        char decBinString[] = "00000000000000";
                                        int c = 0;
                                        while (c < 14) {
                                                posDecVal *= 2;
                                                decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
                                                posDecVal = posDecVal - (int)posDecVal;
                                        }
                                        for (size_t i = 0; i < strlen(decBinString); i++) {
                                                binaryString[i + 18] = decBinString[i];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (tempNumber >= 1024 && tempNumber <= 2047) {
					char wholeNumberBinaryString[] = "00000000000";
					size_t len10 = strlen(wholeNumberBinaryString);
                                        for (int i = len10 - 1; i >= 0; i--) {
                                                if (tempNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (tempNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                tempNumber = tempNumber / 2;
                                        }
					// printf("11 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "0000000000";
					size_t lenlen = strlen(expBinaryString);
                                        for (int i = lenlen - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 10;
                                        char biasBinaryString[] = "00000000";
					size_t len11 = strlen(biasBinaryString);
                                        for (int i = len11 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);
                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        // printf("%s\n", binaryString);
                                        double posDecVal = decimalValue;
                                        char decBinString[] = "0000000000000";
                                        int c = 0;
                                        while (c < 13) {
                                                posDecVal *= 2;
                                                decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
                                                posDecVal = posDecVal - (int)posDecVal;
                                        }
                                        for (size_t i = 0; i < strlen(decBinString); i++) {
                                                binaryString[i + 19] = decBinString[i];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (tempNumber >= 2048 && tempNumber <= 4096) {
					char wholeNumberBinaryString[] = "000000000000";
					size_t len11 = strlen(wholeNumberBinaryString);
                                        for (int i = len11 - 1; i >= 0; i--) {
                                                if (tempNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (tempNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                tempNumber = tempNumber / 2;
                                	}
					// printf("12 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "00000000000";
					size_t len12 = strlen(expBinaryString);
                                        for (int i = len12 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 11;
                                        char biasBinaryString[] = "00000000";
					size_t len13 = strlen(biasBinaryString);
                                        for (int i = len13 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);
                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        // printf("%s\n", binaryString);
                                        double posDecVal = decimalValue;
                                        char decBinString[] = "000000000000";
                                        int c = 0;
                                        while (c < 12) {
                                                posDecVal *= 2;
                                                decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
                                                posDecVal = posDecVal - (int)posDecVal;
                                        }
                                        for (size_t i = 0; i < strlen(decBinString); i++) {
                                                binaryString[i + 20] = decBinString[i];
                                        }
                                        printf("%s\n", binaryString);
				}
			}
		}
		else if (wholeNumber == 0) {
			if (decimalValue == 0) { // ex: 0.0
				printf("%s\n", binaryString);
			}
			else if (decimalValue < 0.0) { // ex: -0.78

			}
			else if (decimalValue > 0.0) { // ex: 0.78
				//TODO
			}
		}
		else if (wholeNumber < 0) {
			if (decimalValue == 0.0) { // ex: -5
				// printf("Number: %d\n", wholeNumber);
				int newWholeNumber = wholeNumber * -1;
				if (newWholeNumber >= 128 && newWholeNumber <= 255) {
                                        char wholeNumberBinaryString[] = "00000000";
					size_t len14 = strlen(wholeNumberBinaryString);
                                        for (int i = len14 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("8 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "0000000";
					size_t len15 = strlen(expBinaryString);
                                        for (int i = len15 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);

                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);

                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);


                                        int biasPlusOneTwoSeven = bias + 7;
                                        char biasBinaryString[] = "00000000";
					size_t len16 = strlen(biasBinaryString);
                                        for (int i = len16 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);

                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        printf("%s\n", binaryString); // printing binary string
				}
				else if (newWholeNumber >= 256 && newWholeNumber <= 511) {
                                        char wholeNumberBinaryString[] = "000000000";
					size_t len17 = strlen(wholeNumberBinaryString);
                                        for (int i = len17 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("9 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "00000000";
					size_t len18 = strlen(expBinaryString);
                                        for (int i = len18 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 8;
                                        char biasBinaryString[] = "00000000";
					size_t len19 = strlen(biasBinaryString);
                                        for (int i = len19 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);

                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (newWholeNumber >= 512 && newWholeNumber <= 1023) {
                                        char wholeNumberBinaryString[] = "0000000000";
					size_t len20 = strlen(wholeNumberBinaryString);
                                        for (int i = len20 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("10 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "000000000";
					size_t len21 = strlen(expBinaryString);
                                        for (int i = len21 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 9;
                                        char biasBinaryString[] = "00000000";
					size_t len22 = strlen(biasBinaryString);
                                        for (int i = len22 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);

                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        printf("%s\n", binaryString);
                                }
				else if (newWholeNumber >= 1024 && newWholeNumber <= 2047) {
                                        char wholeNumberBinaryString[] = "00000000000";
					size_t len23 = strlen(wholeNumberBinaryString);
                                        for (int i = len23 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("11 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "0000000000";
					size_t len24 = strlen(expBinaryString);
                                        for (int i = len24 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 10;
                                        char biasBinaryString[] = "00000000";
					size_t len25 = strlen(biasBinaryString);
                                        for (int i = len25 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);
                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (newWholeNumber >= 2048 && newWholeNumber <= 4096) {
                                        char wholeNumberBinaryString[] = "000000000000";
					size_t len26 = strlen(wholeNumberBinaryString);
                                        for (int i = len26 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("12 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "00000000000";
					size_t len27 = strlen(expBinaryString);
                                        for (int i = len27 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 11;
                                        char biasBinaryString[] = "00000000";
					size_t len28 = strlen(biasBinaryString);
                                        for (int i = len28 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);
                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        printf("%s\n", binaryString);
				}
			}
			else if (decimalValue != 0.0) { // ex: -5.50
				//printf("Float: %f\nWhole Number: %d\nDecimal Value: %f\n", inputFloat, wholeNumber, decimalValue);
				int newWholeNumber = wholeNumber * -1;
				if (newWholeNumber >= 128 && newWholeNumber <= 255) {
                                        char wholeNumberBinaryString[] = "00000000";
					size_t len14 = strlen(wholeNumberBinaryString);
                                        for (int i = len14 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("8 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "0000000";
					size_t len15 = strlen(expBinaryString);
                                        for (int i = len15 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);

                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);

                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);


                                        int biasPlusOneTwoSeven = bias + 7;
                                        char biasBinaryString[] = "00000000";
					size_t len16 = strlen(biasBinaryString);
                                        for (int i = len16 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);

                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        // printf("%s\n", binaryString); // printing binary string



                                        double posDecVal = decimalValue * -1;
                                        char decBinString[] = "0000000000000000";
                                        int c = 0;
                                        while (c < 16) {
                                                posDecVal *= 2;
                                                decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
                                                posDecVal = posDecVal - (int)posDecVal;
                                        }
                                        for (size_t i = 0; i < strlen(decBinString); i++) {
                                                binaryString[i + 16] = decBinString[i];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (newWholeNumber >= 256 && newWholeNumber <= 511) {
                                        char wholeNumberBinaryString[] = "000000000";
					size_t len17 = strlen(wholeNumberBinaryString);
                                        for (int i = len17 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("9 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "00000000";
					size_t len18 = strlen(expBinaryString);
                                        for (int i = len18 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 8;
                                        char biasBinaryString[] = "00000000";
					size_t len19 = strlen(biasBinaryString);
                                        for (int i = len19 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);

                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        // printf("%s\n", binaryString);


					double posDecVal = decimalValue * -1;
                                        char decBinString[] = "000000000000000";
                                        int c = 0;
                                        while (c < 15) {
                                                posDecVal *= 2;
                                                decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
                                                posDecVal = posDecVal - (int)posDecVal;
                                        }
                                        for (size_t i = 0; i < strlen(decBinString); i++) {
                                                binaryString[i + 17] = decBinString[i];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (newWholeNumber >= 512 && newWholeNumber <= 1023) {
                                        char wholeNumberBinaryString[] = "0000000000";
					size_t len20 = strlen(wholeNumberBinaryString);
                                        for (int i = len20 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("10 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "000000000";
					size_t len21 = strlen(expBinaryString);
                                        for (int i = len21 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 9;
                                        char biasBinaryString[] = "00000000";
					size_t len22 = strlen(biasBinaryString);
                                        for (int i = len22 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);

                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        // printf("%s\n", binaryString);

					double posDecVal = decimalValue * -1;
                                        char decBinString[] = "00000000000000";
                                        int c = 0;
                                        while (c < 14) {
                                                posDecVal *= 2;
                                                decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
                                                posDecVal = posDecVal - (int)posDecVal;
                                        }
                                        for (size_t i = 0; i < strlen(decBinString); i++) {
                                                binaryString[i + 18] = decBinString[i];
                                        }
                                        printf("%s\n", binaryString);
                                }
				else if (newWholeNumber >= 1024 && newWholeNumber <= 2047) {
                                        char wholeNumberBinaryString[] = "00000000000";
					size_t len23 = strlen(wholeNumberBinaryString);
                                        for (int i = len23 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("11 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "0000000000";
					size_t len24 = strlen(expBinaryString);
                                        for (int i = len24 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 10;
                                        char biasBinaryString[] = "00000000";
					size_t len25 = strlen(biasBinaryString);
                                        for (int i = len25 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);
                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        // printf("%s\n", binaryString);
                                        double posDecVal = decimalValue * -1;
                                        char decBinString[] = "0000000000000";
                                        int c = 0;
                                        while (c < 13) {
                                                posDecVal *= 2;
                                                decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
                                                posDecVal = posDecVal - (int)posDecVal;
                                        }
                                        for (size_t i = 0; i < strlen(decBinString); i++) {
                                                binaryString[i + 19] = decBinString[i];
                                        }
                                        printf("%s\n", binaryString);
				}
				else if (newWholeNumber >= 2048 && newWholeNumber <= 4096) {
                                        char wholeNumberBinaryString[] = "000000000000";
					size_t len26 = strlen(wholeNumberBinaryString);
                                        for (int i = len26 - 1; i >= 0; i--) {
                                                if (newWholeNumber % 2 == 0) {
                                                        wholeNumberBinaryString[i] = '0';
                                                }
                                                else if (newWholeNumber % 2 != 0) {
                                                        wholeNumberBinaryString[i] = '1';
                                                }
                                                newWholeNumber = newWholeNumber / 2;
                                        }
                                        // printf("12 bit binary string: %s\n", wholeNumberBinaryString);
                                        char expBinaryString[] = "00000000000";
					size_t len27 = strlen(expBinaryString);
                                        for (int i = len27 - 1; i >= 0; i--) {
                                                expBinaryString[i] = wholeNumberBinaryString[i + 1];
                                        }
                                        // printf("Exp bin string: %s\n", expBinaryString);
                                        // int expBinStrToInt = strtol(expBinaryString, NULL, 2);
                                        // printf("expBinStrToInt: %d\n", expBinStrToInt);
                                        int biasPlusOneTwoSeven = bias + 11;
                                        char biasBinaryString[] = "00000000";
					size_t len28 = strlen(biasBinaryString);
                                        for (int i = len28 - 1; i >= 0; i--) {
                                                if (biasPlusOneTwoSeven % 2 == 0) {
                                                        biasBinaryString[i] = '0';
                                                }
                                                else if (biasPlusOneTwoSeven % 2 != 0) {
                                                        biasBinaryString[i] = '1';
                                                }
                                                biasPlusOneTwoSeven = biasPlusOneTwoSeven / 2;
                                        }
                                        // printf("biasBinaryString: %s\n", biasBinaryString);
                                        for (size_t i = 0; i < strlen(biasBinaryString); i++) {
                                                binaryString[i + 1] = biasBinaryString[i];
                                        }
                                        for (size_t k = 0; k < strlen(expBinaryString); k++) {
                                                binaryString[k + 9] = expBinaryString[k];
                                        }
                                        // printf("%s\n", binaryString);
                                        double posDecVal = decimalValue * -1;
                                        char decBinString[] = "000000000000";
                                        int c = 0;
                                        while (c < 12) {
                                                posDecVal *= 2;
                                                decBinString[c++/*haha*/] = '0' + (int)(posDecVal);
                                                posDecVal = posDecVal - (int)posDecVal;
                                        }
                                        for (size_t i = 0; i < strlen(decBinString); i++) {
                                                binaryString[i + 20] = decBinString[i];
                                        }
                                        printf("%s\n", binaryString);
				}
			}
		}
	}
	return 0;
}
