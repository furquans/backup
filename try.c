#include<stdio.h>
#include<stdlib.h>

#include "queue.h"

int main()
{
	int *ptr;
	int i;
	void *q_head;
	int len;

	q_head = create_queue();

	for (i=0;i<10;i++) {
		ptr = malloc(sizeof(*ptr));

		*ptr = i+1;

		add_elem_to_queue(q_head,ptr);
	}

	len = len_queue(q_head);
	printf("Len of queue is : %d\n",len);

	for (i=1;i<=len;i++) {
		ptr = peek_queue(q_head,i);
		if(ptr == NULL)
			break;
		printf("Element is %d\n",*ptr);
	}

	for (i=0;i<10;i++) {
		ptr = remove_elem_from_queue(q_head);
		if(ptr == NULL)
		  break;
		printf("removed %d\n",*ptr);
		free(ptr);
	}

	destroy_queue(q_head);
}
