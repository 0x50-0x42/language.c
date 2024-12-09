#include<stdio.h>

#define __CONST__
#include "def.h"
#undef __CONST__

extern struct nlist *hashtab[];

void displaytable() {

	for(int i = 0; i < HASHSIZE; i++) {
		if(hashtab[i]) {
			struct nlist*temp = hashtab[i];

			while(temp != NULL) {
				printf("%s - %s ", temp->name, temp->defn);
				temp = temp->next;
			}
		}

		else {
			puts("NULL");
		}

		printf("\n");
	}
	
}
