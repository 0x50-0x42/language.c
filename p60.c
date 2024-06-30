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
#define MAXLEN 1000

void _itoa(int, char[]);

int main(void) {
	int n;

	/*
		now, in this machine n is 32 bits(4 bytes)
		and since we didn't mention whether it is
		signed or unsigned, the compiler assumes
		it to be signed so:
			2^32 = 4294967296 numbers
			out of which:
			2147483648 are positive and
			2147483648 are negative that means
			positives are 0 to 2147483647 and
			negatives are -2147483648 to -1;

		now, if we assign n to 2147483648, then,
		instead of storing 2147483648, it will
		actually store -2147483648;

		if n = 2147483649, then it will store
		-2147483647;

		so, I have come up with this formula:

		2147483649 - 2147483648 = 1;
		now,
		-2147483648 + 1 = -2147483647;

		when n = 3147483649 then it will store:

		3147483649 - 2147483648 = 1000000001;
		now,
		-2147483648 + 1000000001 = -1147483647;

	*/

	char s[MAXLEN];

	printf("enter a number: ");
	scanf("%d", &n);

	_itoa(n, s);

	return 0;
}

void _itoa(int n, char s[]) {
}
