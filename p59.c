/*
	itoa():
	convert a number to a string
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

void _itoa(int, char[]);

void reverse(char[]);

int main(void) {

	char s[MAXLEN] = "";

	int n;

	printf("enter a number: ");
	scanf("%d", &n);

	_itoa(n, s);

	printf("string: %s\n", s);

	return 0;
}

void reverse(char s[]) {

	int last = strlen(s) - 1, temp;

	for(int i = last; last - i <= i; i--) {
		temp = s[last - i];
		s[last - i] = s[i];
		s[i] = temp;
	}
}

void _itoa(int n, char s[]) {
	char sign, i = 0;

	if(n < 0) {
		sign = '-';
		n = -n; // making n positive
	}

	do { // this loop will run atleast once i.e. when the string is empty
		s[i++] = n % 10 + '0';
		n /= 10;
	}while(n != 0);

	s[i] = sign;

	reverse(s);
}
