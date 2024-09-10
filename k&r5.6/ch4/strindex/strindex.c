#include<stdio.h>
#include<string.h>

char* strindex(char *source, char *search4) {

	char *base = search4;

	while(*source) {
		if(*search4 == *source) {

			char *found = source;

			while(*source != '\0' && *search4 == *source) {
				search4++;
				source++;
			}


			if(*search4 == '\0')
				return found;

			search4 = base; // reset search4
		}

		if(*source == '\0')
			break;

		source++;
	}

	return NULL;
}
