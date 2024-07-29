/*
   K&R2 4.8:
   	suppose that there will never be more than one character
	of pushback;
	modify getch and ungetch accordingly;
*/

#include<stdio.h>
#include<stdlib.h>
#include<float.h>

#define MAXLEN 1000
#define NUM '0'

int get_op(char[]);

int main(void) {

	char str[MAXLEN];

	int type;

	while((type = get_op(str)) != EOF) {

		switch(type) {
			case NUM:
				printf("%s", str);
				break;

			default:
				printf("%c", type);
		}
	}

	return 0;
}
