#include "sort.h"

/**
 * insertion_sort_list - will sort list using insertion sort
 * @list: Ptr to head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *insert_pos;
	listint_t *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;

	while (current != NULL)
	{
		insert_pos = current;
		prev = current->prev;

		while (prev != NULL && insert_pos->n < prev->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = insert_pos;
			else
				*list = insert_pos;
			if (insert_pos->next != NULL)
				insert_pos->next->prev = prev;
			prev->next = insert_pos->next;
			insert_pos->prev = prev->prev;
			insert_pos->next = prev;
			prev->prev = insert_pos;
			print_list(*list);
			prev = insert_pos->prev;
		}
		current = current->next;
	}
}
