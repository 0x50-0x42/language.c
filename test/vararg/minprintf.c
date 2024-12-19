#include<stdio.h>
#include<stdarg.h>

void minprintf(char *fmt, ...) {

	va_list ap; // argument pointer -> points to each unnamed argument

	va_start(ap, fmt);

	while(*fmt != '\0') {
		if(*fmt == '%') {
			fmt++;
			switch(*fmt) {
				case 'f': // float/double
					printf("%f", va_arg(ap, double));
					break;

				case 'd': // int
					printf("%d", va_arg(ap, int));
					break;
					
				case 'c': // char
					printf("%c", va_arg(ap, int));
					break;

				case 's': // string
					printf("%s", va_arg(ap, char*));
					break;

				default:
					putchar(*fmt);
			}
		}

		else
			putchar(*fmt);

		fmt++;
	}

	va_end(ap);
}
