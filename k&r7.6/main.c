#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	FILE *fd1, *fd2;

	char *str1, *str2;
	
	int fl1 = 0, fl2 = 0; // line numbers of the files


	if(!(fd1 = fopen("file3.txt", "r"))) {
		puts("failed to open file!");
		return 1;
	}

	if(!(fd2 = fopen("file4.txt", "r"))) {
		puts("failed to open file!");
		return 1;
	}

	str1 = calloc(1000, sizeof(char));
	str2 = calloc(1000, sizeof(char));

	int f1 = INT_MAX, f2 = INT_MAX;

	while(f1 != EOF || f2 != EOF) {
		f1 = fscanf(fd1, "%[^\n]%*c", str1);
		f2 = fscanf(fd2, "%[^\n]%*c", str2);

		if(f1 == EOF || f2 == EOF)
			break;

		fl1++, fl2++;

		// if two strings are not the same, then
		if(strcmp(str1, str2) != 0) {
			// print the line numbers and also the strings
			printf("File1: Line %d: %s\n", fl1, str1);
			printf("File2: Line %d: %s\n", fl2, str2);
			break;
		}
	}





	fclose(fd1);
	fclose(fd2);

	// if both the files are identical, then print anything
	if(f1 == EOF && f2 == EOF) ;

	else if(f1 == EOF) {
		printf("File1: Line %d: %s\n", fl1, str1);
		printf("File2: Line %d: %s\n", fl2, str2);
	}

	else if(f2 == EOF){
		printf("File1: Line %d: %s\n", fl1, str1);
		printf("File2: Line %d: %s\n", fl2, str2);
	}

	// free memory
	free(str1);
	free(str2);

	return 0;
}
