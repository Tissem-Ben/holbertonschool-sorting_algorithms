#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *insert_pos;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			insert_pos = tmp->prev;

			if (insert_pos->prev != NULL)
				insert_pos->prev->next = tmp;
			tmp->prev = insert_pos->prev;
			insert_pos->prev = tmp;
			insert_pos->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = insert_pos;
			tmp->next = insert_pos;

			if (tmp->prev == NULL)
				*list = tmp;

			print_list(*list);
		}
	}
}
