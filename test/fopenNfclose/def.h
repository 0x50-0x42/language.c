// an implementation taken from K&R2

#define _BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
	int cnt; /* characters left */
	char *ptr; /* next character position */
	char *base; /* location of buffer */
	int flag; /* mode of file access */
	int fd; /* file descriptor */
} _FILE;

extern _FILE iob[OPEN_MAX];

#define _stdin (&_iob[0])
#define _stdout (&_iob[1])
#define _stderr (&_iob[2])

enum flags {

	// octals
	_READ = 01,
	_WRITE = 02,
	_UNBUF = 04,
	_EOF = 010,
	_ERR = 020
};

int filbuf(_FILE*); /* allocate and fill the input buffer */
int _flushbuf(int, _FILE*);
_FILE *_fopen(char*, char*);


#define _feof(p) (((p)->flag & _EOF) != 0)
#define _ferror(p) (((p)->flag & _ERR) != 0)
#define _fileno(p) ((p)->fd)


#define _getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : filbuf(p))
#define _putc(p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))


#define _getchar() _getc(_stdin)
#define _putchar(x) _putc((x), _stdout)
