#include<stdio.h>
#include<stdlib.h>

#define __CONST__
#include "def.h"
#undef __CONST__

extern struct nlist *hashtab[];

void freeMem() {
	for(int i = 0; i < HASHSIZE; i++) {
		if(hashtab[i]) {
			struct nlist*temp = hashtab[i];
			while(hashtab[i] != NULL) {
				temp = temp->next;
				free(hashtab[i]->name);
				free(hashtab[i]->defn);
				free(hashtab[i]);
				hashtab[i] = temp;
			}
		}
	}
}
