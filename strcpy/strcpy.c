#include<stdio.h>

void _strcpy(char *dest, char *src) {

	int i = 0;

	while((dest[i] = src[i]) != '\0') // first assign, then compare!!
		i++;
}
