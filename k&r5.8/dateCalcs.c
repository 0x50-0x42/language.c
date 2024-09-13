#include<stdlib.h>
#include<stdio.h>

static int months[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // non-leap year
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} // leap year
}; // days of months

unsigned isLeap(int);

int day_of_year(int day, int month, int year) {
	
	unsigned isleap = isLeap(year);

	if(month > 12 || month < 1)
		return EOF;

	if(day <= 0 || day > 31) // negative or 0 days or day number more than 31 not allowed
		return EOF;

	if(isleap) {
		if(day > 29 && month == 2)
			return EOF;
		if((month < 7 && month % 2 == 0 && day > 30) || (month > 7 && month % 2 == 0 && day > 31))
			return EOF;
		if((month < 7 && month % 2 != 0 && day > 31) || (month >= 7 && month % 2 != 0 && day > 30))
			return EOF;
	}

	else {
		if(day > 28 && month == 2)
			return EOF;
		if((month < 7 && month % 2 == 0 && day > 30) || (month > 7 && month % 2 == 0 && day > 31))
			return EOF;
		if((month < 7 && month % 2 != 0 && day > 31) || (month >= 7 && month % 2 != 0 && day > 30))
			return EOF;
	}

	for(int i = 1; i < month; i++)
		day += months[isleap][i];

	return day;
}

unsigned isLeap(int year) {

	if(year % 4 == 0 && (!(year % 100 == 0) || (year % 400 == 0)))
		return 1;
	return 0;
}

void month_day(int year, int doy, int *mn, int *dn) {

	unsigned isleap = isLeap(year);

	if(isleap) {
		if(doy > 366 || doy <= 0) {
			puts("Can't calculate!");
			exit(0);
		}
	}

	else {
		if(doy > 365 || doy <= 0) {
			puts("Can't calculate!");
			exit(0);
		}
	}

	int i;

	for(i = 1; doy > months[isleap][i]; i++)
		doy -= months[isleap][i];
	*mn = i;
	*dn = doy;
}
