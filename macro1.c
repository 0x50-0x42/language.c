#include<stdio.h>

#define max(A, B) ((A) > (B) ? (A) : (B))

int main(void) {

	int x = max(10 + 30, 90 - 45 + 10); // evaluated as: int x = ((10 + 30) > (90 - 45 + 10) ? (10 + 30) : (90 - 45 + 10))

	printf("%d\n", x);
	return 0;
}
