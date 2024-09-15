#include<stdio.h>

#include "def.h"

int main(void) {

	int month, day, year;

	puts("enter date:");

	printf("Month(1-12): ");
	scanf("%d", &month);

	printf("Day: ");
	scanf("%d", &day);

	printf("Year: ");
	scanf("%d", &year);

	int doy = day_of_year(month, day, year);

	printf("Day of year: %d\n", doy);

	printf("enter year: ");
	scanf("%d", &year);

	printf("enter day of the year: ");
	scanf("%d", &doy);

	month_day(year, doy, &month, &day);

	printf("Day of month: %d\nMonth: %d\n", day, month);

	return 0;
}
