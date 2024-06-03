/*
	write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in string s2;
 */

#include<stdio.h>

void squeeze(char[], char[]);

int main(void) {

	char s1[1000];
	char s2[1000];

	printf("enter a string: ");
	scanf("%[^\n]%*c", s1);

	printf("enter second string: ");
	scanf("%[^\n]%*c", s2);

	squeeze(s1, s2);

	printf("Resultant string: %s\n", s1);

	return 0;
}

void squeeze(char s1[], char s2[]) {
	int i, j;
}
