/*
 * helpers.c
 *
 *  Created on: Mar 15, 2013
 *      Author: Michal Banasiak
 */


int integerFromString(const char* string) {
	int number = 0;
	const char* i = &string[0];
	int minus = 0;

	if (*i == '-') {
		minus=1;
		i++;
	}

	while (*i) {
		number*=10;
		number+=(*i)-'0';
		i++;
	}

	if (minus)
		return -number;
	else
		return number;
}

/* http://www.jb.man.ac.uk/~slowe/cpp/itoa.html */
	char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}
