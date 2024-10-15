#include<stdio.h>
#include<stdlib.h>

void Help() {
	puts("Usage: detab [OPTIONS] tab1,[tab2,tab3,...,tabN] [-]");
	puts("OPTIONS:");
	puts("-t tab1    have words separated tab1 characters apart");
	puts("-t LIST    take a list of tabstops, separated by commas in ascending order; put quotes to enclose the tabstops if commas are not provided");
	puts("-h         display this help and exit");
	puts("-          take user input from stdin, it's optional and may be omitted");

	exit(0);
}
