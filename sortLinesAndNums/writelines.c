#include<stdio.h>

void writelines(char **lines, int numLines) {

	for(int i = 0; i < numLines; i++)
		printf("%s\n", lines[i]);
}
