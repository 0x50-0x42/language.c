// celsius to farenheit

#include<stdio.h>

int main(void) {
	float celsius, fahr;

	int upper, lower, step;

	lower = 0;  // lower temperature value
	upper = 300;  // higher temperature value
	step = 20;

	fahr=lower;
	printf("\nCelsius-Farenheit Table\n");

	while(celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32;
		printf("%3.0f\t%6.1f\n", celsius, fahr);

		celsius += step;
	}

	printf("\n");

	return 0;
}
