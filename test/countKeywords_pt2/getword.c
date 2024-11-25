#include<stdio.h>
#include<ctype.h>

#define isscore(val) (val == '_' ? 1 : 0) // if val is an underscore
#define isquote(val) (val == '\'' || val == '\"' ? 1 : 0) // if val is either a single quote or a double quote
#define ishash(val) (val == '#' ? 1 : 0) // preprocessor
#define isfslash(val) (val == '/' ? 1 : 0) // comment

int getch(void);
void ungetch(int);

int getword(char*string, int maxchar) {
	int c;

	while(isspace(c = getch())) // skip the whitespaces
		;

	// for preprocessors
	if(ishash(c)) {
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c) || isquote(c) || c != '\n' && c != EOF)
			*string++ = c;
		ungetch(c);
		*string = '\0';
		return 97;
	}

	// for string constants
	if(isquote(c)) {
		*string++ = c;
		while(isalnum(c = getch()) || c != '\n' && c != EOF && !isquote(c))
			*string++ = c;
		if(isquote(c)) {
			*string++ = c;
		}
		else {
			*string = '\0';
			ungetch(c);
		}

		return 97;
	}

	// for comments
	if(isfslash(c)) {
		*string++ = c;
		c = getch();
		if(isfslash(c)) { // single line comment
			*string++ = c;
			while((c = getch()) != '\n' && c != EOF)
				*string++ = c;
			ungetch(c);
			*string = '\0';
			return 97;
		}

		if(c == '*') { // multi-line comment
			*string++ = c;
			while((c = getch()) != EOF) {
				*string++ = c;
				if(c == '*') {
					if((c = getch()) == '/') { // found the corresponding `*/'
						*string++ = c;
						break;
					}
					*string++ = c;
				}
			}
			*string = '\0';
			return 97;
		}

		// if there is no forward slash after the first forward slash
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c))
			*string++ = c;

		if(isquote(c) || isfslash(c) || ishash(c))
			ungetch(c); // store it in the buffer
		*string = '\0';
		return 97;
	}

	// for direct std input
	if(isalnum(c) || isscore(c) || isquote(c)) {
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c))
			*string++ = c;

		if(isquote(c) || isfslash(c) || ishash(c))
			ungetch(c); // store it in the buffer
		*string = '\0';
		return 97;
	}

	// if c none of the above
	*string = '\0';

	return c;
}
