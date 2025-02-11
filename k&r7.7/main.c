#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

// I think file name should be printed to avoid confusion

const int MAXLEN = 1000;

int main(int argc, char *argv[]) {

	int std_in = 0;

	// if no files are provided as CL arguments
	if(argc == 1)
		std_in = 1; // then take input from stdin

	char *pattern = calloc(MAXLEN, sizeof(char));
	
	// file names were provided as CL arguments
	if(!std_in) {

		printf("enter your pattern:\n");
		scanf("%[^\n]%*c", pattern);

		int const nfiles = argc - 1;

		// create an array of file pointers
		FILE *fp[nfiles];

		for(int i = 0; i < nfiles; i++) {

			// open the n files
			if(!(fp[i] = fopen(argv[i + 1], "r"))) {
				printf("failed to open %s\n", argv[i + 1]);

				// close the previously opened file(s)
				for(int j = 0; j < i; j++)
					fclose(fp[j]);

				// free up memory
				free(pattern);

				return 1;
			}

			// perform pattern searching on the ith file
			find(pattern, fp[i], argv[i + 1]);

			// close the ith file
			fclose(fp[i]);
		}
	}

	// no files were passed as arguments
	else {

		char *text = calloc(MAXLEN, sizeof(char));
		printf("enter your pattern:\n");
		scanf("%[^\n]%*c", pattern);

		printf("enter some sample text:\n");
		getText(text, MAXLEN);

		// passing NULL to tell find that we don't have any file names
		find(pattern, NULL, text);

		// free up memory
		free(text);
	}


	// free memory
	free(pattern);

	return 0;
}
