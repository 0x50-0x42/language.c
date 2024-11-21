#include<stdio.h>
#include<ctype.h>

int _icstrcmp(void*s1, void*s2) {
	char *vec1 = s1;
	char *vec2 = s2;

	while(tolower(*vec1) == tolower(*vec2)) {
		if(*vec1 == '\0')
			return *vec1 - *vec2;
		vec1++, vec2++;
	}

	return *vec1 - *vec2;
}
