#include<stdio.h>
#include<string.h>

int strCmp(char*, char*);

int main(void) {

	char line[] = "hello world";
	char line2[] = "hello world";

	printf("strcmp(): %d\n", strcmp(line, line2));

	printf("strCmp(): %d\n", strCmp(line, line2));

	return 0;
}

int strCmp(char*line1, char*line2) {
	if(*line1 == '\0' || *line1 == '\0')
		return (*line1 - *line2);

	char c1 = *line1++;
	char c2 = *line2++;

	while(c1 == c2) {
		c1 = *line1++;
		c2 = *line2++;

		if(c1 == '\0')
			break;
	}

	return (c1 - c2);
}
