#include<stdio.h>
#include<string.h>

void _getline(char s[], int lim) {

	int c, idx = 0;

	while(((c = getchar()) != EOF) && lim > 0) {
		s[idx++] = c;
		--lim;
	}

	s[idx] = '\0';

	// remove trailing newlines, whitespaces and tabs

	idx = strlen(s) - 1; // taking the last index

	while(s[idx] == '\n' || s[idx] == '\t' || s[idx] == ' ')
		idx--;

	if(idx != strlen(s) - 1)
		s[idx + 1] = '\0';
}
