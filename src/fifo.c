#include "fifo.h"
#include "typedef.h"
bool FIFO_Creat(FIFO * fifo, void**buf, int16_t len)
{
	
	fifo->buf = buf;
	fifo->buftail = buf + len-1;
	fifo->count = 0;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->len = len;
}


bool FIFO_Enqueue(FIFO *fifo, void *data)
{
	void **temp;
	if (fifo->count >= fifo->len)
		return false;
	fifo->count++;
	temp = fifo->tail;
	*temp = data;
	fifo->tail = (uint32_t*)(fifo->tail) + 1;
	if (fifo->tail > fifo->buf + fifo->len - 1)
	{
		fifo->tail = fifo->buf;
	}
	
	return true;
	
}


bool FIFO_Dequeue(FIFO *fifo, void *data)
{
	void **temp;
	if (fifo->count <= 0)
		return false;
	fifo->count--;
	temp = fifo->head;
	data = *temp;
	fifo->head = (uint32_t*)fifo->head + 1;
	if (fifo->head > fifo->buftail +fifo->len-1)
	{
		fifo->head = fifo->buf;
	}
	return true;
}


bool FIFO_Peek(FIFO*fifo,void *data)
{
	if (fifo->count == 0)
		return false;
	return fifo->head;


}


bool FIFO_Clear(FIFO*fifo)
{
	fifo->count = 0;
	fifo->head = fifo->buf;
	fifo->tail = fifo->buf;
	return true;
}