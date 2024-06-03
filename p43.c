/*
	IMPLEMENTATION:
	strcat: concatenate strings

	2nd way
 */

#include<stdio.h>

void str_cat(char[], char[]);

int main(void) {
	char string[1000];
	char concat[1000];

	printf("enter a string: ");
	scanf("%[^\n]%*c", string);

	printf("enter string to concatenate: ");
	scanf("%[^\n]%*c", concat);

	str_cat(string, concat);
	
	printf("Concatenated string: %s\n", string);
	return 0;
}

void str_cat(char s[], char t[]) {
	int i = 0;

	while(s[i] != '\0') // manually calculating length of the string s
		i++;

	for(int j = 0; t[j] != '\0'; j++)
		s[i++] = t[j];

	s[i] = '\0';
}
