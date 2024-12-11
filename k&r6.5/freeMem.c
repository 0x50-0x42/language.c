#include<stdio.h>
#include<stdlib.h>

#define __CONST__
#include "def.h"
#undef __CONST__

extern struct nlist *hashtab[];

void freeMem() {
	for(int i = 0; i < HASHSIZE; i++) {
		struct nlist *temp = hashtab[i];
		while(temp != NULL) {
			free(temp->name);
			free(temp->defn);
			void*t2 = temp;
			temp = temp->next;
			free(t2);
		}
	}
}
