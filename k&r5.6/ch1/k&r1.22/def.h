#ifdef __MAIN__
#define SIZE 1000

int _getline(char*, int);
void fold(char*);
#else
#ifdef __FLD__
#define NCOL 20 // count upto 20 columns
#endif
#endif
