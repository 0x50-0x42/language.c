/*
	The version of itoa() in p59.c does not handle the largest negative number,
	that is, the value of n equal to -2^(wordsize - 1);
	modify _itoa() in p59.c to print that value correctly, regardless of the
	machine on which it runs;

NOTE:
	wordsize is actually the size of int, because n is mentioned in the question
	and we know that n is an integer
*/

#include<stdio.h>

int main(void) {
	int n = -2147483648;
	printf("%d\n", n);
	return 0;
}
