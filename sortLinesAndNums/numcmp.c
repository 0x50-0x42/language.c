#include<stdlib.h>

int numcmp(void *s1, void *s2) {
	double val1, val2;

	val1 = atof((char*)s1);
	val2 = atof((char*)s2);

	if(val1 > val2)
		return 1;

	if(val1 < val2)
		return -1;

	return 0;
}
