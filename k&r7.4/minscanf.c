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

	int success = 0, c, intg, frac;

	double mul = 0.1;

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
<<<<<<< HEAD
							scanf("%lf", (double*)input);
=======
							*(double*)input = 0.0;

							intg = frac = 0;

							// take in the integral part
							while(isdigit(c = getchar()))
								intg = intg * 10 + (c - '0');
							if(c == '.') {
								// take in the fractional part
								while(isdigit(c = getchar()))
									frac = frac * 10 + (c - '0');
							}
							*(double*)input = frac;

							// preparing the fractional part
							while(frac != 0) {
								*(double*)input = *(double*)input * mul;
								frac /= 10;
							}

							*(double*)input = (double)intg + *(double*)input;

							intg = frac = 0;
>>>>>>> 6c02cc4d037ec211014e0a4b95526b4425f76c7a

							success++;

							break;

						default:
							continue;
					}

					break;

				case 'd': case 'i': // integer
					input = va_arg(ap, int*);
<<<<<<< HEAD
					scanf("%d", (int*)input);
=======
>>>>>>> 6c02cc4d037ec211014e0a4b95526b4425f76c7a

					intg = 0;
					if(isdigit(c = getchar())) {
						intg = intg * 10 + (c - '0');
						while(isdigit(c = getchar()))
							intg = intg * 10 + (c - '0');

						*(int*)input = intg;
						success++;
						intg = 0;
					}



					break;

				case 'f': // float/double
					input = va_arg(ap, double*);
<<<<<<< HEAD
					scanf("%lf", (double*)input);
=======
>>>>>>> 6c02cc4d037ec211014e0a4b95526b4425f76c7a

					// decimal part
					if(isdigit(c = getchar())) {
						intg = intg * 10 + (c - '0');
						while(isdigit(c = getchar()))
							intg = intg * 10 + (c - '0');

						if(c == '.') {
							// fractional part
							while(isdigit(c = getchar()))
								frac = frac * 10 + (c - '0');
						}

						*(float*)input = frac;

						while(frac != 0) {
							*(float*)input = *(float*)input * mul;

							frac /= 10;
						}

						*(float*)input = (float)intg + *(float*)input;

						intg = frac = 0;

						success++;
					}

					break;

				case 's': // string
					input = va_arg(ap, char*);
<<<<<<< HEAD
					scanf("%s", (char*)input);
=======

					while(!isspace(c = getchar()))
						*(char*)input++ = c;
>>>>>>> 6c02cc4d037ec211014e0a4b95526b4425f76c7a

					success++;

					break;

				case 'c': // single character
					input = va_arg(ap, char*);
<<<<<<< HEAD
					scanf("%c", (char*)input);
=======
					*(char*)input = getchar();
>>>>>>> 6c02cc4d037ec211014e0a4b95526b4425f76c7a

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
