#include<stdio.h>
#include<string.h>

#include "def.h"

extern struct nlist *hashtab[];
extern unsigned hashval;

struct nlist *lookup(char *s) {
	struct nlist *temp = hashtab[hashval];

	while(temp != NULL) {
		if(strcmp(s, temp->name) == 0)
			return temp;
		temp = temp->next;
	}

	return temp;
}
