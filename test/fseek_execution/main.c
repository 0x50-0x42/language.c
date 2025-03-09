#include<stdio.h>
#include<error.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv) {

	if(argc == 1)
		error(1, errno, "Syntax: ./run filename\n");

	FILE *fp;

	if(!(fp = fopen(argv[1], "r")))
		error(1, errno, "failed to open file...\n");

	// place the file pointer 5 bytes ahead of the current position
	fseek(fp, 5L, SEEK_SET);

	int c;

	while((c = getc(fp)) != EOF)
		printf("%c", c);

	fclose(fp);

	return 0;
}
