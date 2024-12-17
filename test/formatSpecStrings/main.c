#include<stdio.h>

int main(void) {

	char *string = "hello, world";

	printf("%s\n", string);
	printf("%10s\n", string); // field width is 10 characters
	printf("%.10s\n", string); // display atmost 10 characters
	printf("%-10s\n", string); // opposite of field width 10 characters
	printf("%.15s\n", string); // display atmost 15 characters
	printf("%15s\n", string); // field width is 15 characters
	printf("%-15s\n", string); // opposite of field width 15 characters
	printf("%15.10s\n", string); // field width is 15 characters and display atmost 10 characters
	printf("%-15.10s\n", string); // opposite of field width 15 characters, display atmost 10 characters
	return 0;
}
