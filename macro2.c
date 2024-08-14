#include<stdio.h>

#define test(A, B) (printf("[%d, %d]\n", (A), (B)))

int main(void) {

	int i = 1, j = 1;

	test(i++, j++); // replaced as: printf("[%d, %d]\n", i++, j++);

	return 0;
}
