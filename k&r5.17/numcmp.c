#include<stdio.h>
#include<stdlib.h>

int numcmp(void*s1, void*s2) {

	double v1 = atof(s1);
	double v2 = atof(s2);

	if(v1 > v2)
		return 1;
	if(v1 < v2)
		return -1;
	return 0;
}
