#include<stdio.h>
#define IN 1
#define OUT 2

int main(void) {
	int c, len = 0, idx = 0;

	int length[10];  // let's assume that there are going to be 10 words or less than 10 words in a string
	int state = OUT;

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n')
			state = OUT;

		else if(state == OUT)
			state = IN;
	}

	return 0;
}
