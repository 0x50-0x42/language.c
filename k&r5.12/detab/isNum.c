#include<stdio.h>
#include<ctype.h>

int isNum(char *string) {

	if(*string == '\0')
		return 0;

	while(*string != '\0') {
		if(!isdigit(*string))
			return 0;
		string++;
	}

	return 1;
}
