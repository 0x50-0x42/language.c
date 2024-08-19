#include<stdio.h>

void _strcat(char *dest, char *src) {

	while(*dest) // continue until *dest != '\0'
		dest++;

	while((*dest = *src) != EOF)
		dest++, src++;
}
