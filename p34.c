#include<stdio.h>

#define LENGTH 1000

int getLine(char[]);
void syntax(char[], int);

int main(void) {
	int len;

	char program[LENGTH];

	puts("Write a C program:");
	len = getLine(program);

	puts("\nSyntax errors in the C program:");
	syntax(program, len);

	return 0;
}

int getLine(char program[]) {
	int c, idx = 0;

	while((c = getchar()) != EOF && idx != LENGTH - 1)
		program[idx++] = c;

	program[idx] = '\0';

	return idx;
}

void syntax(char line[], int len) {

	char brk[len], quotes[len];
	int idxB = -1, idxQ = -1;

	for(int i = 0; i < len; i++)
		brk[i] = quotes[i] = '\0';

	for(int i = 0; line[i] != '\0'; i++) {

		if(line[i] == '\'') {
			if(idxQ == -1)
				quotes[++idxQ] = line[i];

			else if(quotes[idxQ] == '\'')
				idxQ--;
		}

		else if(line[i] == '\"') {
			if(idxQ == -1)
				quotes[++idxQ] = line[i];

			else if(quotes[idxQ] == '\"')
				idxQ--;
		}

		if((line[i] == '(' || line[i] == '[' || line[i] == '{') && idxQ < 0)
			brk[++idxB] = line[i];

		else if(line[i] == ')' && idxQ < 0) {
			if(brk[idxB] == '(')
				idxB--;
		}

		else if(line[i] == ']' && idxQ < 0) {
			if(brk[idxB] == '[')
				idxB--;
		}

		else if(line[i] == '}' && idxQ < 0) {
			if(brk[idxB] == '{')
				idxB--;
		}
	}

	if(idxB < 0 )
		return;
	else
		puts("Unbalanced parentheses, brackets or braces");

	if(idxQ < 0)
		return;
	else
		puts("Misplaced quotes");
}
