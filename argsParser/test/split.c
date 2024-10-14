#include<string.h>
#include<stdio.h>
#include<ctype.h>

extern char*base;

char* split(char*string) {
	char* str = base;

	if(*base == '\0')
		return base;

	while(*base != '\0') {
		if(isspace(*base)) {
			while(isspace(*base)) {
				*base = '\0';
				base++;
			}

			return str;
		}

		base++;
	}

	return str;
}
