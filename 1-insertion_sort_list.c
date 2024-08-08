#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *swap;

	if (!list || !*list || !(*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->prev->n > temp->n)
		{
			swap = temp->prev;
			if (swap->prev)
				swap->prev->next = temp;
			temp->prev = swap->prev;
			swap->prev = temp;
			swap->next = temp->next;
			if (temp->next)
				temp->next->prev = swap;
			temp->next = swap;
			if (!temp->prev)
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
