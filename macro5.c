#include<stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)

int main(void) {

	float x = 12.0f, y = 5.0f;

	dprint(x/y); // replaced as: printf("x/y" " = %g\n", x/y); which is actually: printf("x/y = %g\n", x/y);
	// string concatenation occurs with #expr and " = %g\n"

	return 0;
}
