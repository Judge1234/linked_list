#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"



// list init

void list_init(List *list, void (*del)(void *data)) {
	list->size = 0;
	list->del = del;
	list->head = NULL;
	list->tail = NULL;

	return;
}


// list delete

void list_delete(List *list) {
	void	*data;

	while (list_size(list) > 0) {
		if (list_del_next(list, NULL, (void**)&data) == 0 && list->del != NULL) {
			list->del(data);
		}
	}

	memset(list, 0, sizeof(List));

	return; 
}


// list insert next

int list_ins_next(List *list, Node *node, const void *data) {
	Node	*new_node;

	if ((new_node = (Node*)malloc(sizeof(Node))) == NULL)
		return -1; 
	new_node->data = (void*)data;

	if (node == NULL) {
		if (list_size(list) == 0)
			list->tail = new_node;
		new_node->next = list->head;
		list->head = new_node;
	}

	else {
		if (node->next == NULL)
			list->tail = new_node;
		new_node->next = node->next;
		node->next = new_node;
	}

	list->size++;

	return 0;
}


// list delete next

int list_del_next(List *list, Node *node, void **data) {
	Node	*old_node;
	
	if (list_size(list) == 0)
		return -1;
	
	if (node == NULL) {
		*data = list->head->data;
		old_node = list->head;
		list->head = list->head->next;
		
		if (list_size(list) == 1)
			list->tail = NULL;
		}
	else {
		if (node->next == NULL)
			return -1;
		
		*data = node->next->data;
		old_node = node->next;
		node->next = node->next->next;

		if (node->next == NULL)
			list->tail = node;
		}
	
	free(old_node);
	list->size--;

	return 0;
}




int main()
{
	return 0;
} 





