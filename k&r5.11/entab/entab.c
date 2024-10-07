#include<stdio.h>
#include<ctype.h>

#define DFLT_TBSTP 8   // the default tabstop

void entab(char *string, int *tabstops, unsigned len) {

	unsigned idx = 0, spaces = 0, chars = 0;


	while(*string == '\t') // skip any leading tabs
		string++;

	char *base = string;

	while(*string != '\0') {

		if(string - base == tabstops[idx] - 1 && idx < len) {

			if(*string == ' ') {
				++spaces;

				if(idx < len && spaces == tabstops[idx]) {
					printf("\t");
					spaces = 0;

					++string;

					if(*(string + 1) != '\0')
						base += (string - base);
				}

				else {
					printf("\t");
					spaces = 0;

					++string;

					if(*(string + 1) != '\0')
						base += (string - base);
				}

				if(len > 1) {
					idx++;

					// relative tabs
					for(int i = idx; i < len; i++)
						tabstops[i] -= tabstops[idx - 1];
				}
			}

			else {
				if(spaces) {
					int sp = 1;
					while(sp <= spaces) {
						printf("%c", *(string - sp));
						sp++;
					}
					spaces = 0;
				}

				if(*(string + 1) != '\0')
					base += ((string - base) + 1);

				if(len > 1) {
					idx++;

					for(int i = idx; i < len; i++)
						tabstops[i] -= tabstops[idx - 1];
				}
			}
		}

		if(*string == ' ' && idx < len)
			++spaces;

		else
			printf("%c", *string);

		++string;
	}
}
