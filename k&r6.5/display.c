#include<stdio.h>

#define __CONST__
#include "def.h"
#undef __CONST__

extern struct nlist*hashtab[];

void display() {

	for(int i = 0; i < HASHSIZE; i++) {
		struct nlist*temp = hashtab[i];
		while(temp != NULL) {
			printf("%s - %s ", temp->name, temp->defn);
			temp = temp->next;
		}

		printf("\n");
	}
}
