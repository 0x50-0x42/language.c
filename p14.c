#include<stdio.h>


int main(void) {
	int c;

	char tab = '\t', backspace = '\b', backslash = '\\';

	while((c = getchar()) != EOF) {
		if(c == tab)
			printf("\\t");
		else if(c == backslash)
			printf("\\\\");
		else if(c == backspace)
			printf("\b");
		else
			putchar(c);
	}

	return 0;
}
