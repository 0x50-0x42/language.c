/*
	K&R2 exercise 4.5:
		add access to library functions like sin, exp and pow;
*/

#include<stdio.h>
#include<float.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define MAXLEN 1000
#define PI 3.14
#define STRT_ANG 180

void push(double);
double pop();
double peek();
double duplicate();
double swap();
void clear();
char _getline(char[], int);

int main(void) {
	
	char rpn[MAXLEN], cmd;

	double op1, op2, state;

	int sign = 1;

	// take reverse polish notation as input
	printf("enter a reverse polish notation: ");
	_getline(rpn, MAXLEN);

	// begin evaluation
	for(int i = 0; rpn[i] != '\0'; i++) {

		switch(rpn[i]) {

			case '+':
				push(pop() + pop());

				break;

			case '-':
				if(rpn[i + 1] != '\0') {
					if(rpn[i + 1] != ' ') {
						sign = -1;
						break;
					}
				}

				op1 = pop();
				op2 = pop();

				push(op2 - op1);

				break;

			case '*':

				push(pop() * pop());

				break;
				
			case '/':

				op1 = pop();
				op2 = pop();

				push(op2 / op1);

				break;

			case '%':

				op1 = pop();
				op2 = pop();

				push((int)op2 % (int)op1);

				break;

			case 'e': case 'E':
				switch(rpn[i + 1]) {
					case 'x': case 'X':
						switch(rpn[i + 2]) {
							case 'p': case 'P':
								push(exp(pop()));
								i+=2;
								break;
							default: // character other than 'n'
								break;
						}

						break;
					default: // character other than 'a'
						break;
				}
				break;

			case '^': // power operator
				op1 = pop();
				push(pow(pop(),op1));
				break;

			case 't': case 'T':
				if((state = peek()) != DBL_MIN)
					printf("top: %f\n", state);
				break;

			case 'd': case 'D':
				if((state = duplicate()) == DBL_MIN)
					puts("stack is empty!");
				break;

			case 's': case 'S':

				// check if it is the first letter of 'sin'
				switch(rpn[i + 1]) {
					case 'i':
						switch(rpn[i + 2]) {
							case 'n':
								push(sin(pop()*PI/STRT_ANG)); // convert to radian
								i+=2;
								break;
							default: // character other than 'n'
								break;
						}

						break;
					default: // character other than 'i'
						if((state = swap()) == DBL_MIN)
							puts("stack is either empty or it has only one element!");
						break;
				}
				break;

			case 'c': case 'C':
				clear();
				break;

			default:
				// check if there is a floating point number or negative number
				if(isdigit(rpn[i])) { // check whether rpn[i] is a digit
					int idx = 0;
					char dig[MAXLEN / 10];
					while(rpn[i] != ' ' && rpn[i] != '\0' && isdigit(rpn[i]))
						dig[idx++] = rpn[i++];
					if(rpn[i] == '.') { // number is a floating-point number
						dig[idx++] = rpn[i++];
						while(rpn[i] != ' ' && rpn[i] != '\0' && isdigit(rpn[i]))
							dig[idx++] = rpn[i++];
					}

					i--;

					dig[idx] = '\0';

					push(sign * atof(dig));
					sign = 1;
				}

				break;

		}
	}

	printf("Result: %.3lf\n", peek());

	return 0;
}
