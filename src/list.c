#include "list.h"
#include <stdlib.h>




static void __list_add(struct list_head*New, struct list_head*prev, struct list_head*next)
{
	New->next = next;
	next->prev = New;
	New->prev = prev;
	prev->next = New;
}

static void __list_del(struct list_head*prev, struct list_head*next)

{
	prev->next = next;
	next->prev = prev;
}
void list_init(struct list_head*list)
{
	list->next = list;
	list->prev = list;
}
void list_add(struct list_head *New, struct list_head *head)
{
	__list_add(New, head, head->next);
}
void list_add_tail(struct list_head*New, struct list_head*head)
{
	__list_add(New, head->prev, head);
}
void list_del(struct list_head*entry)
{
	__list_del(entry->prev, entry->next);
}



