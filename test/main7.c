#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// working of strdup()

int main(void) {

	char *sptr = strdup("hello"); // returns a pointer to the string constant "hello"
	printf("String: %s\n", sptr);

	char string[1000] = "Hello world";
	char *sptr2 = strdup(string);
	printf("String: %s\n", sptr2);

	free(sptr);
	free(sptr2);

	return 0;
}
