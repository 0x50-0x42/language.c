// working of sscanf

// Example: various forms of writing a date

#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char string[MAXCHAR], monthname[MAXCHAR];

	int day, month, year;

	printf("enter date: ");

	while(_getline(string, MAXCHAR) > 0) {
		if(sscanf(string, "%d %s %d", &day, monthname, &year) == 3)
			puts("Valid!");
		else if(sscanf(string, "%d/%d/%d", &day, &month, &year) == 3)
			puts("Valid!");
		else if(sscanf(string, "%d-%d-%d", &day, &month, &year) == 3)
			puts("Valid!");
		else
			puts("Invalid");
	}

	return 0;
}
