#define MAXLEN 1000
#define NUM '0'
#define SIN '$'
#define EXP '#'
#define COS '!'
#define VAR '@'
#define INV '~'
#define PI 3.14
#define STRT_ANGL 180.0

int get_op(char[]);
void push(double);
double pop(void);
double peek(void);
double swap(void);
double duplicate(void);
void clear(void);
