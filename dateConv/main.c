#include<stdio.h>

#include "def.h"


int main(void) {

	int mn, dn, year;

	printf("enter month(1-12): ");
	scanf("%d", &mn);

	printf("enter day of the month: ");
	scanf("%d", &dn);

	printf("enter year: ");
	scanf("%d", &year);

	unsigned doy = day_of_year(dn, mn, year);

	printf("Day of the year: %u\n", doy);

	printf("\nenter year: ");
	scanf("%d", &year);

	printf("enter day of the year: ");
	scanf("%d", &doy);

	month_day(year, doy, &mn, &dn);

	printf("Month: %d\nDay of month: %d\n", mn, dn);

	return 0;
}
