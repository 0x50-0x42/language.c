#define MAXLINES 5000

void qsort(char**, int, int, int(*)(void*, void*));
void qsortR(char**, int, int, int(*)(void*, void*));

int strCmp(void*, void*);
int strCasecmp(void*, void*);
int numcmp(void*, void*);

unsigned readlines(char**, int);
void writelines(char**, int);

void freeMem(void**);
