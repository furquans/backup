#include<stdio.h>
#include<stdlib.h>

typedef struct queue_elem {
	void *data;
	struct queue_elem *next;
}Q_ELEM;

typedef struct queue {
	unsigned int len;
	Q_ELEM *head;
	Q_ELEM *tail;
}Q;

typedef Q_ELEM* Q_ELEM_PTR;
typedef Q* Q_PTR;

/* Func: create_queue
 * Desc: Create a new queue. Returns pointer to head of queue
 *
 */
void *create_queue()
{
	Q_PTR new_queue = malloc(sizeof(*new_queue));
	if (new_queue == NULL) {
		printf("Queue: Error in create_queue:NULL\n");
		exit(1);
	}
	new_queue->head = new_queue->tail = NULL;
	new_queue->len = 0;
	return(new_queue);
}

/* Func: destroy_queue
 * Desc: Delete queue head. 
 *       WARNING!! Responsibility of user to check queue is empty before deleting head
 *
 */
void destroy_queue(void *queue)
{
	Q_PTR q = (Q_PTR)queue;

	if (q == NULL) {
		printf("Queue:Error in destroy_queue:No q\n");
		exit(1);
	}

	free(q);
}

/* Func: add_elem_to_queue
 * Desc: Add an element to tail of the queue
 *
 */
void add_elem_to_queue(void *queue, void *data)
{
	Q_PTR q = (Q_PTR)queue;
	Q_ELEM_PTR new_elem;

	if (q == NULL) {
		printf("Queue: Error in add_elem_to_queue:No q\n");
		exit(1);
	}

	new_elem = malloc(sizeof(*new_elem));

	if (new_elem == NULL) {
		printf("Queue: Error in add_elem_to_queue:NULL\n");
		exit(1);
	}

	new_elem->data = data;
	new_elem->next = NULL;

	if (q->tail == NULL) {
		q->tail = q->head = new_elem;
	} else {
		q->tail->next = new_elem;
		q->tail = new_elem;
	}

	q->len++;
}

/* Func: remove_elem_from_queue
 * Desc: Remove an element from head of the queue
 *
 */
void *remove_elem_from_queue(void *queue)
{
	Q_PTR q = (Q_PTR)queue;
	Q_ELEM_PTR elem;
	void *data;

	if (q==NULL) {
		printf("Queue:Error in remove_elem_from_queue:No q\n");
		exit(1);
	}

	if (q->head == NULL) {
		return(NULL);
	}

	elem = q->head;
	q->head = elem->next;
	if (q->head == NULL) {
		q->tail = NULL;
	}
	q->len--;
	data = elem->data;
	free(elem);
	return(data);
}

/* Func: peek_queue
 * Desc: Peek an element from the queue with given index
 *
 */
void *peek_queue(void *queue, int index)
{
	Q_PTR q = (Q_PTR)queue;
	Q_ELEM_PTR elem;

	if (q == NULL) {
		printf("Queue:Error in peek_queue:No q\n");
		exit(1);
	}

	if (q->len < index) {
		return(NULL);
	}

	elem = q->head;
	index--;

	while(index > 0) {
		elem = elem->next;
		index--;
	}

	return(elem->data);
}

/* Func: len_queue
 * Desc: Returns length of queue
 *
 */
unsigned int len_queue(void *queue)
{
	Q_PTR q = (Q_PTR)queue;

	if (q == NULL) {
		printf("Queue:Error in len_queue:No q\n");
		exit(1);
	}

	return(q->len);
}

/* Func: is_empty_queue
 * Desc: Tells if queue is empty
 *
 */
unsigned int is_empty_queue(void *queue)
{
	return len_queue(queue);
}
