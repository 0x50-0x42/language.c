/*
   K&R2 exercise 4.9

   one part is to replace that char buf[] with int buf[];

   about the 'push-back', not sure, may be ungetch() should check if the character to be pushed back is and EOF or
   any other character, if it finds that the character to be pushed back is an EOF, then should return instead of
   pushing it back;

*/

#include<stdio.h>
#include<float.h>

#define MAXLEN 1000
#define NUM '0'

int get_op(char[]);

int main(void) {
	char s[MAXLEN];

	int type;

	while((type = get_op(s)) != EOF) {
		switch(type) {
			case NUM:
				printf("%s", s);
				break;

			default:
				printf("%c", type);
				break;
		}
	}

	return 0;
}
