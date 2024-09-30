#include<stdio.h>

#define TABSTOP 8

void entab(char *string) {

	int count = 0;
	while(*string != '\0') {
		if(*string == ' ') {
			while(*string == ' ') {
				count++; // count the number of whitespaces
				string++;
			}
			for(int i = 0; i < count / TABSTOP; i++)
				printf("\t");
			for(int i = 0; i < count % TABSTOP; i++)
				printf(" ");
			count = 0;
		}

		else {
			printf("%c", *string);
			string++;
		}

	}
}
