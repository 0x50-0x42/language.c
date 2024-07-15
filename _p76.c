#include<stdio.h>
#include<ctype.h>

#define MAXLEN 1000
#define NUM '0'

void _getline(char[], int);
void push(float);
float pop();
float peek();

int main(void) {
	
	char rpn[MAXLEN];

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

				break;

			case '*':
				break;
				
			case '/':
				break;

			case '%':
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
				}

				break;

		}
	}

	return 0;
}
