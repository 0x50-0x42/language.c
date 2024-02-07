#include<stdio.h>

int main(void) {
	int ch, blanks = 0, tabs = 0, newLines = 0;

	while((ch = getchar()) != EOF) {
		if(ch == '\t')
			++tabs;
		if(ch == ' ')
			++blanks;
		if(ch == '\n')
			++newLines;
	}

	printf("Number of blank spaces: %d\n", blanks);
	printf("Number of tabs: %d\n", tabs);
	printf("Number of newlines: %d\n", newLines);

	return 0;
}
