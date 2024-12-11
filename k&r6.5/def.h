struct nlist {
	char *name;
	char *defn;
	struct nlist *next;
};

#ifdef __MAIN__
int getword(char*, int);
void* install(char*, char*);
void _undef(char*);
void display();
void freeMem();
#endif

#ifdef __GETWD__
int getch();
void ungetch(int);

inline int isscore(int);
inline int ishash(int);
#endif

#ifdef __CONST__
#define HASHSIZE 101
#define MAXCHAR 1000
#endif

#ifdef __INSTL__
unsigned hash(char *);
struct nlist *lookup(char*);
#endif
