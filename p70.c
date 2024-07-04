/*
	write the function strrindex(s,t) which returns the 
	position of the *rightmost* occurrence of t in s, or -1
	if there is none;
*/

#include<stdio.h>
#define MAXLEN 1000

int strrindex(char[], char[]);
void _getline(char[], int);

int main(void) {
	char s[MAXLEN], t[MAXLEN];

	int pos;

	printf("enter some text: ");
	_getline(s, MAXLEN);

	clearerr(stdin); // clearing any EOF in the stream

	printf("enter pattern to be searched: ");
	_getline(t, MAXLEN);

	pos = strrindex(s, t);

	if(pos != -1)
		printf("\"%s\" occurs in index %d\n", t, pos);
	else
		puts("pattern not found!");

	return 0;
}
