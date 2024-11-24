#include<stdio.h>
#include<ctype.h>

int main(void) {

	int c = getchar();

	if(c == EOF)
		puts("EOF");

	if(isalpha(c)) // EOF is not an alphabet
		puts("alpha");
	if(isalnum(c)) // EOF is not an alphabet nor a digit
		puts("alnum");
	return 0;
}
