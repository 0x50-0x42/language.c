/*
	an example from K&R2:
		a function strindex() that prints the line that contains a particular pattern;
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

void strindex(char[], char[]);
void getLine(char[]);

int main(void) {

	char s[MAXLEN] = "", pattern[MAXLEN] = "";

	printf("enter some string: ");
	getLine(s);


	printf("enter pattern: ");
	getLine(pattern);

	strindex(s, pattern);

	return 0;
}

void getLine(char s[]) {
	int c = 0, idx = 0;

	while((c = getchar()) != EOF)
		s[idx++] = c;
	clearerr(stdin);
	int i, last = strlen(s) - 1;

	// remove any trailing newlines, tabs and whitespaces
	for(i  = last; i >= 0; i--)
		if(s[i] != '\n' && s[i] != '\t' && s[i] != ' ')
			break;
	s[i + 1] = '\0';
}

void strindex(char s[], char pattern[]) {

	int len = strlen(pattern);

	for(int i = 0; s[i] != '\0'; i++) {
		if(s[i] == pattern[0]) { // if any character in the string s matches the first character in the pattern
			int count = 0;
			for(int k = 0, j = i; (s[j] == pattern[k]) && s[j] != '\0'; k++, j++) // check if the rest of the characters in s match with pattern
				count++; // basically counting the number of characters matched with pattern
			if(count == len) { // checking if the number of characters matched is same as the length of pattern
				while(i > 0 && s[i] != '\n')
					i--;

				if(s[i] == '\n')
					i += 1;

				while(s[i] != '\n' && s[i] != '\0') {
					printf("%c", s[i]);
					i++;
				}
				printf("\n");
			}
		}
	}
}
