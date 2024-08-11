#include<stdio.h>
#include<ctype.h>

#define NUM '0'
#define SIN '$'
#define COS '!'
#define EXP '#'
#define VAR '@'
#define INV '~'

int getch();

extern int sign, var;

int get_op(char operand[]) {

	int c, idx = 0;
	
	static int pushBack = '\0'; // for push-back character

	c = pushBack == '\0' ? getch() : pushBack;

	pushBack = '\0';

	if(isdigit(c)) { // c IS A DIGIT
		operand[idx++] = c;
		operand[idx] = '\0';

		while(isdigit((c = getch()))) // CONTINUE TAKING IN THE INTEGRAL PART
			operand[idx++] = c;

		if(c == '.') { // TAKE THE DECIMAL(IF IT EXISTS)
			operand[idx++] = c;

			while(isdigit((c = getch()))) // CONTINUE TAKING THE DECIMAL PART(IF IT EXISTS)
				operand[idx++] = c;
		}

		pushBack = c;

		operand[idx] = '\0';

		return NUM;
	}

	if(!isdigit(c)) { // c IS NOT A DIGIT

		// CHECK WHETHER c IS A MINUS
		if(c == '-') {
			int temp = c;

			if(isdigit((c = getch()))) { // IF A DIGIT EXISTS AFTER THE MINUS
				sign = -1;
				operand[idx++] = c;

				while(isdigit((c = getch())))
					operand[idx++] = c;

				if(c == '.') {
					operand[idx++] = c;

					while(isdigit((c = getch())))
						operand[idx++] = c;
				}

				pushBack = c;

				operand[idx] = '\0';

				return NUM;
			}

			else {
				pushBack = c;
				return temp;
			}
		}

		// c IS AN UPPERCASE LETTER(i.e. A VARIABLE)
		if(c >= 'A' && c <= 'Z') {
			var = c;
			return VAR;
		}

		// CHECKING FOR MATHEMATICAL FUNCTIONS AND ALSO SOME COMMANDS
		if(c == 's') {
			int temp = c;
			if((c = getch()) == 'i') {
				if((c = getch()) == 'n') {
					return SIN;
				}

				else {
					pushBack = c;
					return INV;
				}
			}

			pushBack = c;
			return temp;
		}
		
		if(c == 'c') {
			int temp = c;
			if((c = getch()) == 'o') {
				if((c = getch()) == 's') {
					return COS;
				}

				else {
					pushBack = c;
					return INV;
				}
			}

			pushBack = c;
			return temp;
		}

		if(c == 'e') {
			int temp = c;
			if((c = getch()) == 'x') {
				if((c = getch()) == 'p') {
					return EXP;
				}
				
				else {
					pushBack = c;
					return INV;
				}
			}

			pushBack = c;
			return INV;
		}

	}

	return c;
}
