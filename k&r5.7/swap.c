#include<stdio.h>

void swap(char **lines, int i, int j) {
	char *temp;
	temp = lines[i];
	lines[i] = lines[j];
	lines[j] = temp;
}
