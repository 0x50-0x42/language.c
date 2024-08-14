#include<stdio.h>
#include<string.h>

void reverse(char s[], int idx) {
	if((strlen(s) - idx - 1) < idx)
		return;
	char temp = s[idx];
	s[idx] = s[strlen(s) - idx - 1];
	s[strlen(s) - idx - 1] = temp;

	reverse(s, idx + 1);
}
