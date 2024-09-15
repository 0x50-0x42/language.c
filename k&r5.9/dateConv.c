#include<stdio.h>
#include<stdlib.h>

static int days[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

unsigned isLeap(int);

int day_of_year(int month, int day, int year) {


	int *idx;

	unsigned leap = isLeap(year);

	if(month > 12 || month < 1)
		return EOF;

	if(day <= 0 || day > 31) // negative or 0 days or day number more than 31 not allowed
		return EOF;

	if(leap) {
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

	idx = *(days + leap);

	while((idx - *(days + leap)) < month)
		day += *idx++;

	return day;
}

void month_day(int year, int doy, int *month, int *day) {

	int *idx;

	*month = 0;

	unsigned leap = isLeap(year);

	if(leap) {
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

	idx = *(days + leap);

	while(doy - *idx > 0 && (idx - *(days + leap)) < 13) {
		doy -= *idx++;
		(*month)++;
	}
	

	*day = doy;
}

unsigned isLeap(int year) {

	if(year % 4 == 0 && (!(year % 100 == 0) || (year % 400 == 0)))
		return 1;
	return 0;
}
