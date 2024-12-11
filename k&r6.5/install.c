#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define __INSTL__
#include "def.h"
#undef __INSTL__

extern struct nlist *hashtab[];
extern unsigned hashval;

void* install(char *s, char *t) { // add the text and its definition to the table
	hashval = hash(s); // generate a hash value

	struct nlist *temp = lookup(s); // determine whether `s' is present in the table or not

	if(temp == NULL) { // entry doesn't exist
		// create a new entry
		if(hashtab[hashval]) { // check if the hash value leads to a non-NULL list in the table-entry
			struct nlist*temp2 = hashtab[hashval];
			while(temp2->next != NULL)
				temp2 = temp2->next;
			if((temp2->next = malloc(sizeof(struct nlist))) == NULL)
				return NULL;
			temp2->name = strdup(s);
			temp2->defn = strdup(t);
			temp2->next = NULL;
		}

		else {
			if((hashtab[hashval] = malloc(sizeof(struct nlist))) == NULL)
				return NULL;
			hashtab[hashval]->name = strdup(s);
			hashtab[hashval]->defn = strdup(t);
			hashtab[hashval]->next = NULL;
		}
	}

	else { // entry exists
		// supersede the old entry with the new entry
		free(temp->defn); // clear the previous definition
		temp->defn = strdup(t); // add the new definition
	}

	return hashtab[hashval];
}
