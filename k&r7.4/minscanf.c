#include<stdio.h>
#include<ctype.h>
#include<stdarg.h>

#define nullptr NULL

// replace every scanf with an equivalent repitition of getchar()

/*
   > scanf ignores blanks and tabs in its format string
   > scanf skips over blanks, tabs, newlines, etc. as it looks for input values
   > the suppresion character in scanf
 */


int minscanf(char *format, ...) {

	int success = 0;

	va_list ap;

	va_start(ap, format);

	void *input = nullptr;

	while(*format != '\0') {
		if(*format == '%') {
			format++;

			if(*format == '*') {// suppression character
				while(*format != '%')
					format++; // move to the next %
				continue;
			}

			else if(*format == '%') { // if there is a % after %
				format++;
				continue;
			}
			
			switch(*format) {

				case 'l':
					format++;
					switch(*format) {
						case 'f': // double
							input = va_arg(ap, double*);
							scanf("%lf", (double*)input);

							success++;

							break;

						default:
							continue;
					}

					break;

				case 'd': case 'i': // integer
					input = va_arg(ap, int*);
					scanf("%d", (int*)input);

					success++;

					break;

				case 'f': // float/double
					input = va_arg(ap, double*);
					scanf("%lf", (double*)input);

					success++;

					break;

				case 's': // string
					input = va_arg(ap, char*);
					scanf("%s", (char*)input);

					success++;

					break;

				case 'c': // single character
					input = va_arg(ap, char*);
					scanf("%c", (char*)input);

					success++;

					break;

				case ' ':
					while(isspace(*format))
						format++; // ignore the blanks after %
					break;

				default: // none of the above
					clearerr(stdin);
					break;

			}
		}

		else if(*format == '/' || *format == '-' || *format == '.') {
			char ch;
			scanf("%c", &ch);
		}

		format++;
	}

	va_end(ap);

	return success;
}
