#ifndef _ringbuf_h
#define _ringbuf_h
#include "typedef.h"
typedef struct
{
	char* buf;
	int read;
	int write;
	int len;
}ringBuf,*pringBuf;

int_t ringBufInit(ringBuf *rb, uchar_t *buf, uint_t len);
int_t ringBufWrite(ringBuf *rb, uchar_t data);
int_t ringBufRead(ringBuf *rb, uchar_t *data);


#endif
