#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

listint_t *create_node(int value)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

int main(void)
{
	listint_t *head = create_node(3);
	head->next = create_node(1);
	head->next->prev = head;
	head->next->next = create_node(2);
	head->next->next->prev = head->next;

	printf("Original list:\n");
	print_list(head);

	insertion_sort_list(&head);

	printf("Sorted list:\n");
	print_list(head);

	/* Free the list nodes */
	listint_t *tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}

	return 0;
}

