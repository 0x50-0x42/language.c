#include<stdio.h>
#include<stdlib.h>

#define LENGTH 1000

int getLine(char[]);
void remCom(char[], int);

int main(void) {

	char program[LENGTH];

	int len;

	puts("\nWrite a C program:");
	len = getLine(program);

	puts("\nC program after removing comments:");
	remCom(program, len);

	return 0;
}

int getLine(char program[]) {

	int c, idx = 0;

	while((c = getchar()) != EOF)
		program[idx++] = c;

	if(c == EOF)
		program[idx] = '\0';

	return idx;
}

void remCom(char line[], int len) {

	for(int i = 0; line[i] != '\0'; i++) {

		if(i + 1 != len && line[i] == '/') {
			if(line[i + 1] == '/') {
				while(line[i] != '\n' && line[i] != '\0')
					i++;
				putchar('\n');
			}

			else if(i + 1 != len && line[i + 1] == '*') {
				i += 2;

				while(line[i] != '\0') {
					if(line[i] == '*') {
						if(line[i + 1] == '/') {
							i += 2;
							break;
						}
					}

					i++;
				}

				putchar('\n');

				if(line[i] == '\0')
					return;

			}

			else
				putchar(line[i]);
		}

		else
			putchar(line[i]);
	}
}
