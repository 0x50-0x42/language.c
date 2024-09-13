#include<stdio.h>

int main(void) {

	char names[2][10] = {
		"Compiler",
		"GCC"
	};

	printf("Address of 1D array: %p\n", names); // address of the 0th 1D array of 10 characters
	printf("Address of 0th pointer of the 0th 1D array: %p\n", *names); // address of the 0th element of the 0th 1D array
	printf("Address with offset: %p\n", names + 0);
	printf("Value at the 0th pointer of the 0th 1D array: %c\n", *(*(names + 0)+0));
	return 0;
}
