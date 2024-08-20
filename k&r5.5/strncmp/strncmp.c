#include<stdio.h>

int _strncmp(char *s, char *t, int n) {
	for(int i = 0; i < n; i++)
		if(*s++ != *t++)
			return -1;
	return 0;
}
