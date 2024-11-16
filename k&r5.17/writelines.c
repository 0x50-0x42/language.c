#include<stdio.h>

void writelines(int maxfields, char*(*lines)[maxfields], int maxlines) {
	for(int i = 0; i < maxlines; i++) {
		for(int j = 0; j < maxfields && *lines[i][j] != '\0'; j++)
			printf("%s ", lines[i][j]);
		printf("\n");
	}
}
