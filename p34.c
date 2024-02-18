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

	int misplaced = 0, mismatched = 0, errComment = 0, open = 0, single = 0;

	char brk[len], quotes[len], comments[len];
	int idxB = -1, idxQ = -1, idxC = -1;

	for(int i = 0; i < len; i++)
		brk[i] = quotes[i] = comments[i] = '\0';

	for(int i = 0; line[i] != '\0'; i++) {
		if(line[i] == '\n')
			single = 0;

		if(line[i] == '/' && i + 1 != len) {
			if(line[i + 1] == '/') // single line comments are easy to handle
				single = 1;

			else if(line[i + 1] == '*') {
				if(single); // if this multi-line comment is a part of the single comment then we ignore it
				else if(!open) {
					comments[++idxC] = line[i];
					comments[++idxC] = line[i + 1];
					open = 1;
					i++;
				}

				else
					errComment++;
			}
		}

		else if(line[i] == '*' && i + 1 != len) {
			if(line[i + 1] == '/') {
				if(open) {
					idxC -= 2;
					open = 0;
				}

				else
					errComment++;
			}
		}

		if(line[i] == '\'') {

			if(single || open) ; // if this single quote is a part of a comment then ignore it

			else if(idxQ == -1)
				quotes[++idxQ] = line[i];

			else if(quotes[idxQ] != '\'')
				misplaced++;

			else if(quotes[idxQ] == '\'')
				idxQ--;
		}

		else if(line[i] == '\"') {

			if(single || open) ; // if this single quote is a part of a comment then ignore it

			else if(idxQ == -1)
				quotes[++idxQ] = line[i];

			else if(quotes[idxQ] != '\"')
				quotes[++idxQ] = line[i];

			else if(quotes[idxQ] == '\"')
				idxQ--;
		}

		if((line[i] == '(' || line[i] == '[' || line[i] == '{' || line[i] == '<') && idxQ < 0)
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

		else if(line[i] == '>' && idxQ < 0) {
			if(brk[idxB] == '<')
				idxB--;
			else
				mismatched++;
		}
	}

	if(!mismatched && idxB < 0) {
		if(!misplaced && idxQ < 0) {
			if(!open && !errComment)
				return;

			else if(open)
				puts("Unclosed comment");

			else if(errComment)
				puts("Nested comments not allowed");
		}

		else {
			puts("Misplaced quotes");

			if(!open && !errComment)
				return;

			else if(open)
				puts("Unclosed comment");

			else if(errComment)
				puts("Nested comments not allowed");
		}
	}

	else {
		puts("Mismatched parentheses, brackets, braces...");

		if(!misplaced && idxQ < 0) {

			if(!open && !errComment)
				return;

			else if(open)
				puts("Unclosed comment");

			else if(errComment)
				puts("Nested comments not allowed");

			return;
		}

		else {
			puts("Misplaced quotes");

			if(!open && !errComment)
				return;

			else if(open)
				puts("Unclosed comment");

			else if(errComment)
				puts("Nested comments not allowed");
		}
	}
}
