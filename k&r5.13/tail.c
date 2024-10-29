#include<stdio.h>

void tail(char **string, int lines, int n) {
	if(n >= lines)
		for(int i = 0; i < lines; i++)
			printf("%s\n", string[i]);
	else {
		char **target = string + (lines - n);

		for(int i = 0; i < n; i++)
			printf("%s\n", target[i]);
	}
}
