#include<stdio.h>

void convert();

int main(void) {
	for(int i=0; i<=300; i+=20)
		convert(i);
	return 0;
}

void convert(farh)
	int farh; {
		printf("%3d\t%6.1f\n", farh, (5.0/9.0)*(farh-32));
	}
