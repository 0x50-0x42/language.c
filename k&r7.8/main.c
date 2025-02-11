#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {

	if(argc == 1) {
		puts("no files specified");
		return 1;
	}

	FILE *fp;

	int c, page = 1;

	for(int i = 1; i < argc; i++) {
		if(!(fp = fopen(argv[i], "r")))
			puts("failed to open file!");
		else {
			printf("\n\n\t\t\t\tFile:  %s\n\t\t\t\t--------------\n", argv[i]);
			while((c = getc(fp)) != EOF)
				putc(c, stdout);
			printf("\n\n\t\t\t\tPage number: %d\n\n\n\n\n\n", page);
			page++;

			fclose(fp);
		}
	}

	return 0;
}
