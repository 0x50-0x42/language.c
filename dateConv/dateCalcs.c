static int months[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // non-leap year
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} // leap year
}; // days of months

unsigned isLeap(int);

int day_of_year(int day, int month, int year) {

	unsigned isleap = isLeap(year);

	int doy = 0;
	for(int i = 1; i < month; i++)
		doy += months[isleap][i]; // so cleverly used the leap year status with the matrix; AMAZING!! Thanks K&R2(this was in the book)!
	doy += day;

	return doy;
}

unsigned isLeap(int year) {
	if(year % 4 == 0 && (!(year % 100 == 0) || (year % 400 == 0)))
		return 1;
	return 0;
}

void month_day(int year, int doy, int *mn, int *dn) {
	unsigned isleap = isLeap(year);

	*dn = 0;

	for(int i = 1; i <= 12; i++) {
		if(*dn + months[isleap][i] >= doy) {
			*mn = i; // record the month number
			*dn = doy - *dn;
			return;
		}

		*dn += months[isleap][i]; // go on incrementing the number of days
	}
}
