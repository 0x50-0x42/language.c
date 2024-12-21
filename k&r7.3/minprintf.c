#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdarg.h>

int minprintf(char *fmt, ...) {

	va_list ap; // argument pointer

	int field = 0, chars = 0, num, numlen = 0;

	va_start(ap, fmt);

	while(*fmt != '\0') {
		if(*fmt == '%') { // if format is %
			fmt++;
			if(isspace(*fmt))
				fmt++;

			if(isdigit(*fmt)) { // if there is a number after %
				while(isdigit(*fmt)) { // then take it
					field = field * 10 + (*fmt - '0');
					fmt++;
				}

				if(*fmt == '.') { // if there is a dot after the last number
					fmt++; // move to the next character
					while(isdigit(*fmt)) { // accept only if there is a number
						chars = chars * 10 + (*fmt - '0');
						fmt++;
					}
				}
			}

			switch(*fmt) {
				case 'i': case 'd': // integer
					printf("%*.*d", field, chars, va_arg(ap, int));
					break;

				case 'f': // float/double
					printf("%*.*lf", field, chars, va_arg(ap, double));
					break;

				case 'c': // integer - single
					printf("%c", va_arg(ap, int));
					break;

				case 'x': case 'X': // hexadecimal
					printf("%*.*x", field, chars, va_arg(ap, int));
					break;

				case 'o': // octal
					printf("%*.*o", field, chars, va_arg(ap, int));
					break;

				case 's': // string
					if(chars)
						printf("%*.*s", field, chars, va_arg(ap, char*));
					else
						printf("%*s", field, va_arg(ap, char*));
					break;

				default:
					putchar(*fmt);
					break;
			}
		}

		else {
			putchar(*fmt);
		}

		fmt++;

		field = chars = 0;
	}

	va_end(ap);
}
