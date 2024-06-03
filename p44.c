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

	int k, j;

	char s3[1000];

	for(int i = 0; s2[i] != '\0'; i++) {
		for(k = j = 0; s1[j] != '\0'; j++) {
			if(s1[j] != s2[i])
				s3[k++] = s1[j];
			s3[k] = '\0';
		}

		for(k = 0; s3[k] != '\0'; k++)
			s1[k] = s3[k];
	}
}
