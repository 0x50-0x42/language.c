/*
	write the function itob(n, s, b) that converts the integer n into a base b character 
	representation in the string s in particular, itob(n, s, 16) formats n as a hexadecimal integer in s;
*/

#include<stdio.h>
#include<limits.h>

#define MAXLEN 1000

void _itob(int, char[], int);

int main(void) {

	/*
		2 -> binary
		8 -> octal
		16 -> hexadecimal
	*/

	int n;

	char s[MAXLEN];

	printf("enter a number: ");
	scanf("%d", &n);

	_itob(n, s, 16); // convert n to hexadecimal representation in string s

	return 0;
}

void _itob(int n, char s[], int base) {
}
