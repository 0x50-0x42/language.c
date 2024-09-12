#define MAXLINES 10

#include<stdio.h>

void writelines(char **line) {
	for(int i = 0; i < MAXLINES; i++)
		printf("%s\n", *(line + i));
}
