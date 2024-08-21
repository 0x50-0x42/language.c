#include<stdio.h>
#include "def.h"

int main(void) {

	char line[SIZE];

	puts("enter some text:");

	int count;

	while((count = _getline(line, SIZE)) != EOF)
		if(count > 80)
			printf("%s\n", line);

	return 0;
}
