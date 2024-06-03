/*
	IMPLEMENTATION:

	squeeze: delete all 'c' from string s;
 */


#include<stdio.h>

void squeeze(char[], int);

int main(void) {

	char string[1000];

	printf("enter a string: ");
	scanf("%[^\n]%*c", string);

	squeeze(string, 'c');

	printf("String: %s\n", string);

	return 0;
}

void squeeze(char s[], int c) {

	int i, j;

	for(i = j = 0; s[i] != '\0'; i++) {
		if(s[i] != 'c')
			s[j++] = s[i];

		s[j] = '\0';
	}
}

/*
	string s is copying its contents into itself except for the index where it finds 'c';
 */
