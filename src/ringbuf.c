#include"ringbuf.h"
#include "typedef.h"

int_t ringBufInit(ringBuf *rb, uchar_t *buf, uint_t len)
{
	rb->buf = buf;
	rb->len = len;
	rb->read = 0;
	rb->write = 0;
	return 0;
}


int_t ringBufWrite(ringBuf *rb, uchar_t data)
{
	
	rb->buf[rb->write++]= data;
	
	if (rb->write >= rb->len)
	{
		rb->write = 0;
	}
	return 0;
}
int_t ringBufRead(ringBuf *rb, uchar_t *data)
{
	*data = rb->buf[rb->read++];
	if (rb->read >=rb->len)
	{
		rb->read = 0;
	}
	return 0;
}