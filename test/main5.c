#include<stdio.h>

int main(void) {

	char string[] = "hello world";

	char (*line)[12];

	line = &string;

	if(line == &string)
		printf("%p == %p\n", line, &string);

	if((*line + 0) == string)
		printf("\t%p == %p\n", *line + 0, string);

	if(*(*line + 0) == string[0])
		printf("%c == %c\n", *(*line + 0), string[0]);
	if((*line)[1] == string[1])
		printf("%c == %c\n", *(*line + 1), string[1]);
	if(line[0][2] == string[2])
		printf("%c == %c\n", line[0][2], string[2]);

	return 0;
}
