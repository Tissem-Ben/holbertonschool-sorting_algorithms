#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *temp;

	if (!list || !*list || !(*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		key = current;
		current = current->next;

		while (key->prev && key->n < key->prev->n)
		{
			temp = key->prev;
			key->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = key;
			key->prev = temp->prev;
			temp->prev = key;
			temp->next = current;
			if (current)
				current->prev = temp;

			if (key->prev == NULL)
				*list = key;

			print_list(*list);
		}
	}
}
