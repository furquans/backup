#ifndef _QUEUE_H_
#define _QUEUE_H_

void *create_queue();
void destroy_queue(void *);
void add_elem_to_queue(void *, void *);
void *remove_elem_from_queue(void *);
void *peek_queue(void *, int);
unsigned int len_queue(void *);

#endif
