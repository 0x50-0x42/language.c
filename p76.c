/*
TODO: handle floating-point values as well(it was handled in K&R2 example); this is not part of the exercise;

	K&R2: exercise 4.3
*/

// TODO: handle floating-point values and negative values

#include<stdio.h>
#include<ctype.h>

#define MAXLEN 1000

void _getline(char[], int);
void push(int);
int pop();
int peek();

int main(void) {

	char rpn[MAXLEN];

	printf("enter a reverse polish notation: ");

	_getline(rpn, MAXLEN);

	for(int i = 0; rpn[i] != '\0'; i++) {
		switch(rpn[i]) {
			case '-':
				break;
			case '+':
				break;
			case '*':
				break;
			case '/':
				break;
			default:
				break;
		}
	}


	return 0;
}
