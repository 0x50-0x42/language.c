#include<stdio.h>

char* strrindex(char *source, char *search4) {

	char *found = NULL, *base = search4, *last;

	while(*source) {
		if(*search4 == *source) {
			last = found; // store the last found address
			found = source;

			while(*source != '\0' && *search4 == *source)
				search4++, source++;

			if(*search4 != '\0') {
				found = NULL;
				found = last;
			}

			search4 = base; // reset search4
		}

		source++;
	}

	return found;
}
