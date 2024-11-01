#include<stdio.h>
#include<string.h>

int str_case_cmp(void*vec1, void*vec2) {
	return strcasecmp((char*)vec1, (char*)vec2);
}
