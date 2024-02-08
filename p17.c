#include<stdio.h>

int main(void) {
	int c, prev = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			if(prev != ' ' && prev != '\t' && prev != '\n')
				putchar((c = '\n'));
		}
		
		else {
			putchar(c);
		}

		prev = c;
	}

	return 0;
}
