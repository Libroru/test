#ifndef _fifo_h
#define _fifo_h

#include "typedef.h"
typedef struct
{
	void **buf;
	void **buftail;
	int16_t count;
	void *head;
	void *tail;
	int16_t len;
}FIFO;


bool FIFO_Creat(FIFO * fifo, void**buf, int16_t len);

bool FIFO_Enqueue(FIFO *fifo, void *data);

bool FIFO_Dequeue(FIFO *fifo, void *data);

bool FIFO_Peek(FIFO*fifo, void *data);

bool FIFO_Clear(FIFO*fifo);
#endif
