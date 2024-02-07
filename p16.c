#include<stdio.h>

#define IN 1  // inside a word
#define OUT 0  // outside a word

int main(void) {
	int c, words = 0, lines = 0, characters = 0, state=OUT;

	while((c = getchar()) != EOF) {
		if(c == '\n')
			++lines;
		if(c == '\n' || c == ' ' || c == '\t')
			state = OUT;
		else if(state == OUT) {
			state = IN;
			++words;
		}

		++characters;
	}

	printf("Characters: %d\n", characters);
	printf("Words: %d\n", words);
	printf("Lines: %d\n", lines);

	return 0;
}
