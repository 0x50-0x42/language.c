#include<stdio.h>

int str_cmp(char*, char*);

int main(void) {

	char line1[] = "home$$earth";
	char line2[] = "homeearth";

	printf("%d\n", str_cmp(line1, line2));

	return 0;
}

int str_cmp(char*line1, char*line2) {
	if(*line1 == '\0' || *line2 == '\0') {
		if(*line1 == '\0') {
			while((*line2 < '0' && *line2 > ' ') || (*line2 > '9' && *line2 < 'A') || (*line2 > 'Z' && *line2 < 'a') || (*line2 > 'z'))
				line2++;
			return *line1 - *line2;
		}

		if(*line2 == '\0') {
			while((*line1 < '0' && *line1 > ' ') || (*line1 > '9' && *line1 < 'A') || (*line1 > 'Z' && *line1 < 'a') || (*line1 > 'z'))
				line1++;
			return *line1 - *line2;
		}
	}

	while(*line1 == *line2) {
		line1++, line2++;

		while((*line1 < '0' && *line1 > ' ') || (*line1 > '9' && *line1 < 'A') || (*line1 > 'Z' && *line1 < 'a') || (*line1 > 'z'))
			line1++;

		while((*line2 < '0' && *line2 > ' ') || (*line2 > '9' && *line2 < 'A') || (*line2 > 'Z' && *line2 < 'a') || (*line2 > 'z'))
			line2++;

		if(*line1 == '\0')
			break;
	}

	return *line1 - *line2;
}
