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

extern SWTimer_t head;

bool SWTimer_Init();
bool SWTimer_Creat(SWTimer_t * st, SWTimerFunc func, void * para, uint16_t timeout, uint8_t timeid, uint8_t stop);
bool SWTimer_Start(uint8_t timerid);
bool SWTimer_Stop(uint8_t timerid);
void SWTimer_Tick(void);

#endif
