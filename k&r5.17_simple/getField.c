#include<stdio.h>
#include<ctype.h>
#include<string.h>

void *alloc(unsigned);

char *getField(char *string, int field) {

	if(!strlen(string)) // an empty string doesn't have any fields
		return NULL;

	char *iterator = string;
	char *fieldPtr = string;

	int fieldno = 1; // by default, a string has 1 field

	while(*iterator != '\0') {
		if(isspace(*iterator)) {
			while(isspace(*iterator))
				iterator++;

			if(fieldno == field)
				break;

			if(*iterator != '\0') {
				fieldPtr = iterator;
				fieldno++;
			}

			else
				break;
			continue;
		}

		iterator++;
	}

	char *temp = alloc(strlen(fieldPtr));

	strcpy(temp, fieldPtr);

	int i;

	for(i = 0; temp[i] != '\0' && !isspace(temp[i]); i++)
		;

	if(temp[i] != '\0')
		temp[i] = '\0';

	string = temp;

	return string;
}
