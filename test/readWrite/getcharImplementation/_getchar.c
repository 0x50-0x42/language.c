#include<stdio.h>
#include<unistd.h>

int _getchar() {

	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
