#include<stdio.h>

//inline int isdotexclamQ(int);
inline int isdotexclamQ(int);

int main(void) {
	int c = getchar();

	if(isdotexclamQ(c))
		puts("YES");
	return 0;
}

int isdotexclamQ(int val) {
	return val == '.' || val == '!' || val == '?' ? 1 : 0;
}
