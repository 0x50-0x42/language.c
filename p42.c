/*
	IMPLEMENTATION:

	strcat: concatenate string
 */


#include<stdio.h>
#include<string.h>

void str_cat(char[], char[]);

int main(void) {

	char string[1000];

	char concat[1000];

	printf("enter a string: ");
	scanf("%[^\n]%*c", string);

	printf("enter string to be concatenated: ");
	scanf("%[^\n]%*c", concat);

	str_cat(string, concat);

	printf("Concatenated string: %s\n", string);
	return 0;
}

void str_cat(char s[], char t[]) {

	int j = strlen(s);

	for(int i = 0; t[i] != '\0'; i++) {
		s[j++] = t[i];
	}

	s[j] = '\0';
}
