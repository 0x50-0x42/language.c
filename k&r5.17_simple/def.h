#define MAXLINES 5000
#define MAXCHAR 1000

int readlines(char*, int);
void writelines(char**, int);

int numcmp(void*, void*);
int _strcmp(void*, void*);
int _icstrcmp(void*, void*);
int _strdircmp(void*, void*);
int _icstrdircmp(void*, void*);

void *alloc(unsigned);
void freeMem();

void _qsort(char**, int, int, int, int (*)(void*, void*));
void _qsortR(char**, int, int, int, int (*)(void*, void*));
