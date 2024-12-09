#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define __INSTALL__
#include "def.h"
#undef __INSTALL__

extern unsigned hashval;
extern struct nlist *hashtab[];

void install(char *s, char *t) {

	hashval = hash(s); // generate the hash value for string `s'

	// look for string `s' in the table
	struct nlist *temp = lookup(s);

	if(temp == NULL) { // new entry
		temp = hashtab[hashval];
		if(temp == NULL) {
			hashtab[hashval] = malloc(sizeof(struct nlist));
			hashtab[hashval]->name = strdup(s);
			hashtab[hashval]->defn = strdup(t);
			hashtab[hashval]->next = NULL;
		}

		else {

			while(temp->next != NULL)
				temp = temp->next;
			temp->next = malloc(sizeof(struct nlist));
			temp->next->name = strdup(s); // (*(*temp).next).name = strdup(s);
			temp->next->defn = strdup(t);
			temp->next->next = NULL;
		}
	}

	else { // `s' already exists in the table
		return;
	}
}
