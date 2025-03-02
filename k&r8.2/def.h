// an implementation taken from K&R2

#define _BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
	int                                cnt; /* characters left */
	char                               *ptr; /* next character position */
	char                               *base; /* location of buffer */
	int                                fd; /* file descriptor */

	// fields
	unsigned int                       _READ:1;
	unsigned int                       _WRITE:1;
	unsigned int                       _UNBUF:1;
	unsigned int                       _EOF:1;
	unsigned int                       _ERR:1;
} _FILE;

extern _FILE iob[OPEN_MAX];

#define _stdin (&_iob[0])
#define _stdout (&_iob[1])
#define _stderr (&_iob[2])

int filbuf(_FILE*); /* allocate and fill the input buffer */
int _flushbuf(int, _FILE*);
_FILE *_fopen(char*, char*);
_FILE *_fclose(_FILE*);


#define _feof(p) (((p)->flag & (p)->_EOF) != 0)
#define _ferror(p) (((p)->flag & (p)->_ERR) != 0)
#define _fileno(p) ((p)->fd)


#define _getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : filbuf(p))
#define _putc(p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))


#define _getchar() _getc(_stdin)
#define _putchar(x) _putc((x), _stdout)
