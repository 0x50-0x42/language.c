#include<stdio.h>

int _getline(char *str, int lim) {

	int idx = 0, c;

	while((c = getchar()) != EOF)
		str[idx++] = c;
	idx--;

	while(str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n') // remove trailing whitespaces, tabs and newlines
		idx--;

	str[idx + 1] = '\0';

	return (idx + 1);
}
