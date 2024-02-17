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

	int misplaced = 0, mismatched = 0, errComment = 0;

	char brk[len], quotes[len], comments[len];
	int idxB = -1, idxQ = -1, idxC = -1;

	char open = '\0', close = '\0';

	for(int i = 0; i < len; i++)
		brk[i] = quotes[i] = comments[i] = '\0';

	for(int i = 0; line[i] != '\0'; i++) {

		// TODO: handle comments now!!

		if(line[i] == '\'') {
			if(idxQ == -1)
				quotes[++idxQ] = line[i];

			else if(quotes[idxQ] != '\'')
				misplaced++;

			else if(quotes[idxQ] == '\'')
				idxQ--;
		}

		else if(line[i] == '\"') {
			if(idxQ == -1)
				quotes[++idxQ] = line[i];

			else if(quotes[idxQ] != '\"')
				quotes[++idxQ] = line[i];

			else if(quotes[idxQ] == '\"')
				idxQ--;
		}

		if((line[i] == '(' || line[i] == '[' || line[i] == '{') && idxQ < 0)
			brk[++idxB] = line[i];

		else if(line[i] == ')' && idxQ < 0) {
			if(brk[idxB] == '(')
				idxB--;
			else
				mismatched++;
		}

		else if(line[i] == ']' && idxQ < 0) {
			if(brk[idxB] == '[')
				idxB--;
			else
				mismatched++;
		}

		else if(line[i] == '}' && idxQ < 0) {
			if(brk[idxB] == '{')
				idxB--;
			else
				mismatched++;
		}
	}

	if(!mismatched) {
		if(!misplaced)
			return;
		else
			puts("Misplaced quotes");
	}

	else {
		puts("Mismatched parentheses, brackets, braces...");

		if(!misplaced)
			return;
		else
			puts("Misplaced quotes");
	}
}
