struct tree {
	int count;
	char *word;
	struct tree *left;
	struct tree *right;
};

#define MAXCHAR 1000

#ifdef __GTWD__
inline int ishash(int);
inline int isquote(int);
inline int isdotexclamQ(int);
inline int isfslash(int);
inline int isscore(int);

int getch();
void ungetch(int);
#endif

#ifdef __MAIN__
int getword(char*, int);
struct tree*
addtree(struct tree*, char*, int);

void treeprint(struct tree*);

void freeMem();
#endif

#ifdef __ADDNODE__
void*talloc();
#endif
