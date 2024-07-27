#include<stdio.h>
#include<string.h>

extern int bufp;

extern char buffer[];

void ungets(char s[]) {

	int i = strlen(s) - 1;
	buffer[++bufp] = '\0';

	while(i >= 0) {
		buffer[++bufp] = s[i];
		i--;
	}
}
