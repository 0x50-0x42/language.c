/*
	write a function escape(s, t) that converts characters like newline and tab into visible escape
	sequences like \n and \t as it copies the string t to s; use a switch; write a function for the
	other direction as well, converting esacpe sequences into the real characters;
*/


#include<stdio.h>

void escape(char[], char[]);
void descape(char[], char[]); // opposite of escape()

int main(void) {

	char s[100] = "";
	char t[100] = "";
	char r[100] = "";

	int idx = 0;

	printf("enter a string:\n");

	int c;

	while((c = getchar()) != '.')
		t[idx++] = c;

	printf("String:\n%s\n", t);

	escape(s, t);
	printf("converted string is\n%s\n", s);

	descape(r, s);
	printf("\nrestored string is\n%s\n", r);

	return 0;
}

void escape(char s[], char t[]) {

	int idx = 0;

	for(int i = 0; t[i] != '\0'; i++) {
		switch(t[i]) {
			case '\n':
				s[idx] = '\\';
				s[++idx] = 'n';
				++idx;
				break;
			case '\t':
				s[idx] = '\\';
				s[++idx] = 't';
				++idx;
				break;
			default:
				s[idx++] = t[i];
				break;
		}
	}
}

void descape(char r[], char s[]) {

	int idx = 0;

	for(int i = 0; s[i] != '\0'; i++) {

		switch(s[i]) {
			case '\\':
				if(s[i + 1] == 'n') {
					r[idx++] = '\n';
					i++;

					if(s[i] == '\0')
						break;
				}
				else if(s[i + 1] == 't') {
					r[idx++] = '\t';
					i++;

					if(s[i] == '\0')
						break;
				}

				break;
			default:
				r[idx++] = s[i];
				break;
		}
	}
}
