#define SIZE 100
#define MAXLINES 10

#ifdef __QSRT__
void swap(char**, int, int);
#endif


#ifdef __MAIN__
char* alloc(int);
void afree();

void readlines(char**, int);
void writelines(char**);

void qsort(char**, int, int);
#endif

#ifdef __RDLN__
int _getline(char*, int);
#endif