#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *getField(char *string, int field) {

	if(!strlen(string)) // if no string has been entered then return NULL
		return NULL;

	char *iterator = string;
	char *fieldPtr = string; // for pointing to the string after a whitespace or the initial string

	int fieldno = 1; // by default, a string has one field

	while(*iterator != '\0') {
		if(isspace(*iterator)) { // if a whitespace is encountered
			while(isspace(*iterator)) // then skip all the whitespaces
				iterator++;

			if(fieldno == field)
				break;

			fieldno++; // we have entered into the next field

			if(*iterator != '\0') // check if there are any more characters after the whitespace(s)
				fieldPtr = iterator; // move to the string after this/these whitespace(s)

			else // otherwise, there's no string in this field
				fieldno--;
			continue;
		}
		iterator++;
	}

	if(fieldno != field)
		return NULL;

	const int len = strlen(fieldPtr); // after the required string is found, take its length

	char temp[len]; // create a separate string with the length taken previously

	strcpy(temp, fieldPtr); // we don't want to disturb the original string

	int i;

	for(i = 0; temp[i] != '\0' && !isspace(temp[i]); i++) // loop until the first whitespace(if any) or the null character
		;

	if(temp[i] != '\0') // if a whitespace is encountered, then replace it with the null character
		temp[i] = '\0';

	string = temp; // cannot send the local variable's address

	return string; // required string
}
