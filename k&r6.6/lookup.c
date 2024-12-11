#include<stdio.h>
#include<string.h>

#include "def.h"

extern struct nlist *hashtab[];
extern unsigned hashval;

struct nlist* lookup(char *s) {

	struct nlist *temp = hashtab[hashval];

	while(temp != NULL && strcmp(temp->name, s) != 0)
		temp = temp->next;
	return temp;
}
