#include<stdio.h>
#include<string.h>

int strrindex(char s[], char t[]) {

	int count = 0;

	for(int i = strlen(s) - 1; i >= 0; i--) {
		// compare each character of s with the last character of t
		for(int k = strlen(t) - 1; s[i] == t[k] && i >= 0; k--, i--)
			count++; // this loop will continue as long as s[j] == t[k] and j >= 0

		if(count == strlen(t))
			return i;
		count = 0;
	}

	return -1;
}
