#ifndef _list_h
#define _list_h




struct list_head
{
	struct list_head *prev, *next;
};

 
void list_init(struct list_head*list);
void list_head_init(struct list_head*list);
void list_add(struct list_head*New, struct list_head*head);
void list_add_tail(struct list_head*New, struct list_head*head);
void list_del(struct list_head*entry);

#endif