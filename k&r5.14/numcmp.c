#include<stdlib.h>

int numcmp(char *s1, char *s2) {

	double val1, val2;

	val1 = atof(s1);
	val2 = atof(s2);

	if(val1 > val2)
		return 1;
	if(val1 < val2)
		return -1;
	return 0;
}
