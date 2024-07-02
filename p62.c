/*
	write a version of itoa() that accepts three arguments instead of two;
	the third argument is a minimum field width; the converted number must
	be padded with blanks on the left if necessary to make it wide enough;

	basically it should work like when we specify field with in printf();
*/

#include<stdio.h>
#include<string.h>
#include<limits.h>

#define MAXLEN 1000

void _itoa(int, char[], int);
void reverse(char[]);

int main(void) {

	int n;

	char s[MAXLEN] = "";

	printf("enter a number: ");
	scanf("%d", &n);

	_itoa(n, s, 5);

	printf("Formatted string:%s\n", s);

	return 0;
}

void reverse(char s[]) {

	int last = strlen(s) - 1;
	char temp;

	for(int i = last; (last - i) <= i; i--) {
		temp = s[last - i];
		s[last - i] = s[i];
		s[i] = temp;
	}
}

void _itoa(int n, char s[], int fieldWidth) {

	int idx = 0;

	do {
		s[idx++] = n % 10 + '0';
		n /= 10;
	}while(n != 0);

	int len = strlen(s);

	if(len != fieldWidth)
		for(int i = 0; i < fieldWidth - len; i++)
			s[idx++] = ' ';

	reverse(s);
}
