struct tree {
	char*word;
	int count;
	struct tree *left;
	struct tree *right;
};

#ifdef __MAIN__

#define MAXCHAR 1000

int getword(char*, int);

struct tree*
addtree(struct tree*, char*); // returns 0 if string isn't a duplicate otherwise 1

void showTree(struct tree*);
void freeTree();
#endif

#ifdef __ADDNODE__
void* talloc();
#endif
