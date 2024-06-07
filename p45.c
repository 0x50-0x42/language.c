/*
	write the function any(s1, s2), which returns the first location in the string s1 where any character from the string s2 occurs,
	or -1 if s1 contains no characters from s2.
*/

#include<stdio.h>

int any(char[], char[]);

int main(void) {

	char s1[1000], s2[1000];

	printf("enter first string: ");
	scanf("%[^\n]%*c", s1);

	printf("enter second string: ");
	scanf("%[^\n]%*c", s2);

	int location = any(s1, s2);

	printf("Location: %d\n", location);

	return 0;
}

int any(char s1[], char s2[]) {
	for(int i = 0; s1[i] != '\0'; i++) {
		for(int j = 0; s2[j] != '\0'; j++)
			if(s1[i] == s2[j])
				return i;
	}

	return -1;
}
