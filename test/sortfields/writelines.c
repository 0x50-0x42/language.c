#include<stdio.h>

void writelines(int maxfields, char* (*line)[maxfields], int nlines) {
	for(int i = 0; i < nlines; i++) {
		for(int j = 0; j < maxfields && *line[i][j] != '\0'; j++)
			printf("%s ", line[i][j]);
		printf("\n");
	}
}
