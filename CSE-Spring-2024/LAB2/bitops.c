#include "bitops.h"

/*
 * Return and of x and y
 * Points: 3
 */
int and_op(int x, int y) {
	return x&y;
}

/* 
 * Return or of x and y
 * Points: 3
 */
int or_op(int x, int y) {
	return x|y;
}

/*
 * Return xor of x and y
 * Points: 3
 */
int xor_op(int x, int y) {
	return x^y;
}

/*
 * Clear `b`th byte of x
 * Points: 7
 */
int masking_and(int x, int b) {
	x = and_op(x, ~(0xff << (b * 8)));
	return x;
}

/*
 * Set `b`th byte of x
 * Points: 7
 */
int masking_or(int x, int b) {
	x = or_op(x, 0xff << (b * 8));
	return x;
}

/*
 * Toggle `b`th byte of x
 * Points: 7
 */
int masking_xor(int x, int b) {
	x = xor_op(x, 0xff << (b * 8));
	return x;
}

/*
 * Shift x to the left by `sc` # of bits
 * Points: 3
 */
int shifting_left_op(int x, int sc) {
	return x << sc;
}

/*
 * Shift x to the right by `sc` # of bits
 * Points: 3
 */
int shifting_right_op(int x, int sc) {
	return x >> sc;
}


/*
 * Return logical not of x
 * Points: 3
 */
int bang(int x) {
	return !x;
}

/*
 * Print binary string representation for x
 * Points: 30
 */
void bit_conversion(int x) {
	char binaryString[32];

	int i = 0;
	while (x > 0) {
		if (x % 2 == 0) {
			binaryString[i] = '0';
		}
		else if (x % 2 != 0) {
			binaryString[i] = '1';
		}
		x = x / 2;
		i++;
	}
	for (int k = i - 1; k >= 0; k--) {
		printf("%c", binaryString[k]);
	}
	puts("");
}
