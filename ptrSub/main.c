#include<stdio.h>

int main(void) {

	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int *p1;
	int *p2;

	p1 = p2 = v;

	puts("Pointer subtraction");
	for(int i = 0; i < 10; i++)
		printf("%ld\n", (p1 + i) - p2);

	puts("\nArray");

	for(int i = 0; i < 10; i++)
		printf("%d\n", v[(p1 + i) - p2]); // displays array elements

	puts("\nArray using pointer");
	for(int i = 0; i < 10; i++)
		printf("%d\n", *(p1 + i));

	return 0;
}
