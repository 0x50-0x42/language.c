#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "def.h"
#include "constants.h"

#define NUM '0'

int sign = 1;
unsigned idx = 0;

int main(int argc, char *argv[]) {

	int type;

	double operand;

	if(argc == 1) {
		puts("Usage: expr [reverse polish notation]");
		return 1;
	}
	printf("argc: %d\n", argc);
	argc--;

	char number[SIZE];

	argv++;

	while(argc != 0) {
		while((type = parse(*argv, number)) != '\0') {
			switch(type) {
				case NUM:
					push(sign * atof(number));
					sign = 1;
					break;

				case '+':
					push(pop() + pop());
					break;

				case '-':
					operand = pop();
					push(pop() - operand);
					break;

				case '/':
					operand = pop();
					push(pop() / operand);
					break;

				case '*':
					push(pop() * pop());
					break;

				case '%':
					operand = pop();
					push((int)pop() % (int)operand);
					break;

				case '^':
					operand = pop();
					push(pow(pop(), operand));
					break;

				case SIN:
					push(sin(pop() * PI / STRT_ANGL));
					break;

				case COS:
					push(cos(pop() * PI / STRT_ANGL));
					break;

				case TAN:
					push(tan(pop() * PI / STRT_ANGL));
					break;

				case EXP:
					push(exp(pop()));
					break;

				default:
					break;
			}
		}
		argc--;
		argv++;
		idx = 0;
	}

	printf("Result: %.3f\n", peek());

	return 0;
}
