#include<stdio.h>

void _strncat(char *s, char *t, int n) {
	while(*s) // continue until *s is '\0'
		s++;

	for(int i = 0; i < n; i++)
		*s++ = *t++;
	*s = '\0';
}
