struct tree {
	char *word;
	int count;
	struct tree*left;
	struct tree*right;
};

#ifdef __MAIN__
#define MAX 1000
int getword(char*, int);

struct tree*
addnode(struct tree*, char*);

struct tree*
mkrevtree(struct tree*, struct tree**);

void treeprint(struct tree*);
void freeMem();
#endif

#ifdef __GETWD__
int getch();
void ungetch(int);

inline int isscore(int);
#endif

#ifdef __ADDNODE__
void *talloc();
#endif

#ifdef __REVTREE__
void revtree(struct tree*, struct tree**);
#endif
