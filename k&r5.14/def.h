#define MAXLINES 5000

void freeMem(void**);

unsigned readlines(char**, int);
void writelines(char**, unsigned);

int numcmp(void*, void*);
int strCmp(void*, void*);

void qsort(char**, int, int, int(*)(void*, void*));
void qsortR(char**, int, int, int(*)(void*, void*));
