#include<stdio.h>
#include<string.h>

void reverse(char s[]) {

	unsigned long len = strlen(s);

	for(int i = 0; (len - i - 1) >= i; i++) {
		if(s[0] != '-') {
			char temp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = temp;
		}

		else {
			if((len - i - 1) >= (i + 1)) {
				char temp = s[i + 1];
				s[i + 1] = s[len - i - 1];
				s[len - i - 1] = temp;
			}
		}
	}
}
