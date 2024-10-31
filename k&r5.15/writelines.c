#include<stdio.h>

void writelines(char**lines, int nlines) {
	for(int i = 0; i < nlines; i++)
		printf("%s\n", lines[i]);
}
