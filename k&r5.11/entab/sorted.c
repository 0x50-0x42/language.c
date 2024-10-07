#include<stdio.h>

int sorted(int*tabstops, int len) {
	for(int i = 0; i < len - 1; i++)
		if(tabstops[i] - tabstops[i + 1] > 0)
			return -1;

	return 0;
}
