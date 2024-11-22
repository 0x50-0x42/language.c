#include<stdio.h>
#include<string.h>
#include "def.h"

struct {
	int len;
	char *str;
} *p, var;

int main(void) {

	p = &var;

	p->str = alloc(MAXCHAR); // equivalent to (*p).str = alloc(MAXCHAR);
	p->len = 0;

	strcpy(p->str, "hello world");

	printf("str: %s\n", p->str);
	printf("len: %d\n", p->len);

	printf("len: %d\n", p->len);

	p->len++;
	printf("len: %d\n", p->len);
	
	// both of these are equivalent to each other
	printf("%c\n", *p->str);
	printf("%c\n", *(*p).str);

	// both of these are equivalent to each other
	printf("%c\n", *p->str++);
	printf("%c\n", *(*p).str++); // this will display 'e' because str was incremented in the previous line

	// the following statements, save the printf statements, are equivalents of each other
	(*p->str)++;
	printf("%c\n", *p->str);

	(*(*p).str)++;
	printf("%c\n", *(*p).str);



	//----------------------
	freeMem(p->str);

	return 0;
}
