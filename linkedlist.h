#ifndef L_LIST_H
#define L_LIST_H

#include <stdlib.h>


// main data structures

typedef struct L_Node {
	void		*data;
	struct L_Node	*next;
} Node; 


typedef struct L_List {
	int		size;
	int		(*match)(const void *key1, const void *key2);
	void		(*del)(void *data);
	Node		*head;
	Node		*tail;
} List; 


// public L_List interface

void list_init(List *list, void (*del)(void *data)); 

void list_delete(List *list); 

int list_ins_next(List *list, Node *node, const void *data); 

int list_del_next(List *list, Node *node, void **data); 

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, node) ((node) == (list)->head ? 1 : 0)
#define list_is_tail(node) ((node)->next == NULL ? 1 : 0)
#define list_data(node) ((node)->data)
#define list_next(element) ((element)->next)
#endif


