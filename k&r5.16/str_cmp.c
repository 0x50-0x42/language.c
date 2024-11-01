#include<stdio.h>
#include<string.h>

int str_cmp(void*vec1, void*vec2) {
	return strcmp((char*)vec1, (char*)vec2);
}
