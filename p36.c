// K&R exercise 2-2

/* Write a loop equivalent to the for loop below without using && or ||
 *
 * for(int i = 0; i < lim - 1 && (c = getchar) != '\n' && c != EOF; ++i)
 *
 */

#include<stdio.h>

#define LEN 1000

int main(void) {
	int c, idx = 0;

	char line[LEN];

	for(int i = 0; i < LEN - 1; ++i) {
		if((c = getchar()) != '\n') {
			if(c != EOF)
				line[idx++] = c;
			else {
				printf("\nString: %s\n", line);
				return 255;
			}
		}

		else
			i = LEN - 1;
	}

	printf("String: %s\n", line);

	return 0;
}
