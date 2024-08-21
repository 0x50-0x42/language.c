#include<stdio.h>

void copy(char *dest, char *src) {
	while(*src)
		*(dest++) = *(src++); // *dest++ = *src++
}
