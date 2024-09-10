#include<string.h>

void reverse(char *s) {
	int len = strlen(s), i = 0;
	char *base = s;

	while(*s != '\0') {
		if(len - i - 1 >= i) {
			char temp = *s;
			*s = *(base + (len - i - 1));
			*(base + (len - i - 1)) = temp;
		}

		s++;
		i++;
	}
}
