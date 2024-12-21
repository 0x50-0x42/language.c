#include<stdio.h>

int main(void) {
	int a = 10, b = a + 10;

	int np = printf("a = %d, b = %d\n", a, b);

	np = printf("%d\n", np);

	np = printf("Hello, world: %d\n", np);
	printf("%d\n", np);

	printf("% d\n", np); // one whitespace is allowed

	printf("% 10d\n", np); // one whitespace is allowed

	printf("%10.10d\n", np); // field is 10 characters wide and 10 digits will be displayed
	// that is the whole field will be filled

	printf("%10.5d\n", np); // field is 10 characters wide and 5 digits will be displayed
	// that is there will be five whitespace before the digits

	printf("%10.4d\n", np);

	printf("%.4d\n", np);

	printf("%10.15d\n", np); // field is 10 characters wide and 15 digits will be displayed
	// that is the field will be filled

	double c = 10.0;

	printf("%10.15f\n", c); // field is 10 characters wide and there are 15 digits after the .
	// that is the whole field will be field because the total number of digits + the .
	// total number of digits = integral digits and fractional digits

	printf("%10.5f\n", c); // field is 10 characters wide and there are 5 digits after the .
	// that is the there will be only two whitespaces before the floating point number because
	// the total number of digits is 7(integral digits + fractional digits) + the . which
	// makes a total of 8 characters

	char *string = "hello world";

	printf("%s\n", string);
	printf("%20s\n", string); // field is 20 characters wide that is there
	// will be 9 whitespaces before the string

	printf("%20.3s\n", string); // field is 20 characters wide 


	// single character
	char schar = 'a';

	printf("%10c\n", schar);

	printf("%10x\n", np);

	int f = 10, ch = 10;

	float flt = 10.5;

	printf("%d", np);

	return 0;
}
