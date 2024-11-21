#include<stdio.h>

void writelines(char **strings, int nlines) {
	for(int i = 0; i < nlines; i++)
		printf("%s\n", strings[i]);
}
