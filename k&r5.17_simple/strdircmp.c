#include<stdio.h>
#include<ctype.h>

int _strdircmp(void*s1, void*s2) {
	char *vec1 = s1;
	char *vec2 = s2;

	while(!isdigit(*vec1) && !isspace(*vec1) && !isalpha(*vec1))
		vec1++;

	while(!isdigit(*vec2) && !isspace(*vec2) && !isalpha(*vec2))
		vec2++;

	while(*vec1 == *vec2) {
		if(*vec1 == '\0')
			return *vec1 - *vec2;

		while(!isdigit(*vec1) && !isspace(*vec1) && !isalpha(*vec1))
			vec1++;

		while(!isdigit(*vec2) && !isspace(*vec2) && !isalpha(*vec2))
			vec2++;

		vec1++, vec2++;
	}

	return *vec1 - *vec2;
}
