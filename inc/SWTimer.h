#ifndef _swtimer_h
#define _swtimer_h
#include "typedef.h"
#include "list.h"
typedef bool(*SWTimerFunc)(void*);


typedef struct
{
	struct list_head link;
	SWTimerFunc func;
	void* para;
	uint16_t timeout;
	uint16_t dlyctr;
	uint8_t timerid;
	uint8_t stoped;	
}SWTimer_t;

typedef struct list_head  Timerlink;
#endif
