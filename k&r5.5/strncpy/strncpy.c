#include<stdio.h>

void _strncpy(char *s, char *t, int n) {
	for(int i = 0; i < n; i++)
		*s++ = *t++; // *(s++) = *(t++)
	*s = '\0';
}
