struct tree {
	int val;
	struct tree *left;
	struct tree *right;
};

#ifdef __MAIN__
#define MAXCHAR 1000
// functions and constants to be included in main()
int getint();

struct tree*
addtree(struct tree*, int);

void displayTree(struct tree*);
#endif

#ifdef __ADDNODE__
void* talloc(int); // memory allocation function for a tree node
#endif
