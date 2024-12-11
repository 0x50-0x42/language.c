#include<stdio.h>
#include<stdlib.h>

#define __INSTL__
#include "def.h"
#undef __INSTL__

extern struct nlist *hashtab[];
extern unsigned hashval;

void _undef(char *s) {

	hashval = hash(s);

	struct nlist *temp = lookup(s); // determine whether the name exists or not

	if(temp == NULL)
		return;
	else {
		if(hashtab[hashval] == temp) {
			hashtab[hashval] = hashtab[hashval]->next;
			free(temp);
		}
		
		else {
			struct nlist*temp2 = hashtab[hashval];
			while(temp2->next != temp)
				temp2 = temp2->next;
			temp2->next = temp->next;
			free(temp);
		}
	}
}
