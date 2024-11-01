#include<stdio.h>
#include<stdlib.h>

int numcmp(void*vec1, void*vec2) {
	double val1 = atof((char*)vec1);
	double val2 = atof((char*)vec2);

	if(val1 > val2)
		return 1;
	if(val1 < val2)
		return -1;
	return 0;
}
