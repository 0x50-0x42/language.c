#include<stdio.h>

void reverse(char *s, int len) {
	for(int i = 0; len - i - 1 >= i; i++) {
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
