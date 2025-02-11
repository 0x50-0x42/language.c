#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern const int MAXLEN;

void find(char *pattern, FILE *fp, char *fileName) {

	char *string = calloc(MAXLEN, sizeof(char));
	char *parser;

	if(fp) {

		printf("\n\nFile name: %s\n_____________________\n", fileName);

		// read one whole string from the file and
		while(fscanf(fp, "%[^\n]%*c", string) != EOF) {
			parser = string;

			// parse the whole string from left to right to check for the pattern
			while(*parser != '\0') {
				// if the first character of the pattern matches the parser string
				if(pattern[0] == *parser) {
					int i = 0;

					// then check if the rest of the pattern matches the parser
					for(; pattern[i] == *parser && *parser != '\0'; i++, parser++);
					// if pattern was exhausted
					if(pattern[i] == '\0') {

						// then we have found our pattern in the string
						printf("%s\n", string);
						break; // break out of this while loop
					}
				}

				parser++;
			}
		}

	}

	else {
		while(*fileName != '\0') {
			
			// read in a string from the text
			sscanf(fileName, "%[^\n]%*c", string);
			parser = string;

			// find the pattern
			while(*parser != '\0') {

				if(pattern[0] == *parser) {
					int i = 0;
					for(; pattern[i] == *parser && *parser != '\0'; i++, parser++);
					if(pattern[i] == '\0') {
						printf("%s\n", string);
						break;
					}
				}

				parser++;
			}

			fileName += strlen(string) + 1;
		}
	}

	free(string);


}
