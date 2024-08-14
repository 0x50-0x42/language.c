#include<stdio.h>

#define paste(front, back) front ## back


int main(void) {

	int name1 = 10;

	printf("Value is %d\n", paste(name, 1)); // replaced: name ## 1 which is name1
	return 0;
}
