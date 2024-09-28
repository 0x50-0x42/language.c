#include<stdio.h>
#include<stdlib.h>

#include "def.h"
#include "constants.h"

int sign = 1;

int main(int argc, char *argv[]) {

	int type;

	char number[SIZE];
	
	argv++;

	// handle the arguments
	while((type = parse(*argv, number)) && argc != 1) {

		switch(type) {

			case NUM:
				push(sign * atof(number));
				break;

			case '-':
				break;

			case '+':
				break;

			case '/':
				break;

			case '*':
				break;

			case '%':
				break;

			default:
				break;

		}

		argc--;
	}

	return 0;
}
