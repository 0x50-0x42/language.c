#define MAXCHAR 1000

struct tree {
	char *string;
	struct tree *left;
	struct tree *right;
};


#ifdef __MAIN__
int getword(char*, int);

struct tree*
addtree(struct tree*, char*);

void treeprint(struct tree*);

void freeMem();
#endif

#ifdef __ADDNODE__
void* talloc();
#endif
