#include<stdio.h>

void subarray(int*);

int main(void) {

	int v[] = {12, 14, 16, 18, 20, 22, 24, 26, 28, 30};

	subarray(v + 5);

	printf("\n");
	return 0;
}

void subarray(int *v) {
	puts("\nFirst half:");
	for(int i = 0; i <= 5; i++)
		printf("%d ", v[- i]); // *(v - i); backward indexing(possible because it's a subarray)

	puts("\nLater half:");
	for(int i = 0; i < 5; i++)
		printf("%d ", *(v + i)); // v[i]

}
