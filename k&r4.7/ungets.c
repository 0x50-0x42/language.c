#include<stdio.h>
#include<string.h>

void ungetch(int);

void ungets(char s[]) {

	int i = strlen(s) - 1;
	//buffer[++bufp] = '\0';

	/* I guess this can be done using ungetch() as well
	while(i >= 0) {
		buffer[++bufp] = s[i];
		i--;
	}
	 */

	ungetch('\0'); // inserting the null character

	while(i >= 0) {
		ungetch(s[i]);
		i--;
	}
}
