#include<stdio.h>

int main(void) {
	int c, words = 0, lines = 0, characters = 0, prev = 0;

	while((c = getchar()) != EOF) {
		if(c == '\n')
			++lines;

		if((c == ' ' || c == '\t' || c == '\n') && (prev != ' ' && prev != '\t' && prev != 0))
			++words;

		++characters;
		prev = c;
	}

	printf("Number of words: %d\n", words);
	printf("Number of lines: %d\n", lines);
	printf("Number of characters: %d\n", characters);

	return 0;
}
