/*
	trim() function that removes trailing blanks, tabs, newlines
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

int trim(char[]);

int main(void) {

	char s[MAXLEN] = "";

	printf("enter a string: ");
	scanf("%[^\n]%*c", s);

	int length = trim(s);

	printf("trimmed string: %s\n", s);
	return 0;
}

int trim(char s[]) {

	int n;

	for(n = strlen(s) - 1; n >= 0; n--) // starting from the last index, we will go on towards the left
		if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n') // if the current character is neither whitespace nor tab or newline
			break; // then we will exit from the loop
	s[n + 1] = '\0'; // trim the trailing characters(trailing whitespaces, tabs or newlines) by putting a null character
	return n; // return the modified length
}
