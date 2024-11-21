#include<stdio.h>

int _strcmp(void*s1, void*s2) {
	char *vec1 = s1;
	char *vec2 = s2;

	while(*vec1 == *vec2) {
		if(*vec1 == '\0')
			return *vec1 - *vec2;
		vec1++, vec2++;
	}

	return *vec1 - *vec2;
}
