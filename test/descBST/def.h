struct tree {
	int val;
	struct tree*left;
	struct tree*right;
};

#ifdef __MAIN__
int getint();
struct tree*addnode(struct tree*, int);
void treeprint(struct tree*);
void freeMem();
#endif

#ifdef __GETINT__
int getch();
void ungetch(int);
#endif

#ifdef __ADDNODE__
void* talloc();
#endif
