#include<stdio.h>
#include<string.h>

int main(void) {
	int c, prev = '\0', idx = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ') {
			if(prev != ' ')
				putchar(c);
		}

		else {
			putchar(c);
		}

		prev=c;
	}

	return 0;
}
