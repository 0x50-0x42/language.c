#include<stdio.h>
#include<string.h>

int strend(char *s, char *t) {
	while(*s) {
		if(strcmp(s, t) == 0)
			return 1;
		s++;
	}

	return 0;
}
