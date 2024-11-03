#include<stdio.h>

void writelines(char*(*line)[3], int numLines, int maxfield) {
	for(int i = 0; i < numLines; i++) {
		for(int j = 0; j < maxfield && *(line[i][j]) != '\0'; j++)
			printf("%s ", line[i][j]);
		printf("\n");
	}
}
