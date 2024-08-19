/*
   K&R2 exercise 5.3

   strcat() from chapter-2

   void strcat(chat s[], char t[]) {
   	int i, j;

	i = j = 0;

	while(s[i] != '\0')
		i++;
	while((s[i++] = t[j++]) != '\0')
		;
   }

 */

#include<stdio.h>
#include "def.h"

int main(void) {

	char s1[SIZE], s2[SIZE];

	printf("enter first string: ");
	_getline(s1, SIZE);

	clearerr(stdin);

	printf("enter second string: ");
	_getline(s2, SIZE);

	_strcat(s1, s2); // concatenate s2 to s1

	printf("concatenated string: %s\n", s1);

	return 0;
}
