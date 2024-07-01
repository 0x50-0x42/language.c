/*
	modify _itoa() from p59.c so that it handles the largest negative number,
	that is, the value of n equal to -2^(wordsize - 1) and prints the value correctly;
*/

#include<stdio.h>
#include<limits.h>
#include<string.h>

#define MAXLEN 1000

void _itoa(int, char[]);
void reverse(char[]);

int main(void) {

	int n;

	char s[MAXLEN];

	printf("INT_MIN: %d\n", INT_MIN);

	_itoa(INT_MIN, s);

	printf("String is: %s\n", s);

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
	char sign;
	int lNeg = 0, idx = 0;

	if(n < 0) {
		sign = '-'; // take the sign

		if(n == INT_MIN) {
			lNeg = 1; // setting it to one so that we know that n was actually increased
			n += 1; // increase n by 1
		}

		n = -n; // make n positive
	}

	do {
		s[idx] = lNeg == 1 ? (n % 10) + 1 + '0': n % 10 + '0';
		lNeg = 0;
		n /= 10;
		idx++;
	}while(n != 0);

	if(sign == '-')
		s[idx++] = sign;
	s[idx] = '\0';

	reverse(s);
}
