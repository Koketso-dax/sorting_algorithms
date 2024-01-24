#include "sort.h"

/**
 * swap_nodes - swapes 2 nodes in doubly linked list
 * @start: ptr to first node
 * @end: ptr to second node
 * @list: Double ptr to head of linked list
 */
void swap_nodes(listint_t *start, listint_t *end, listint_t **list)
{
	listint_t *temp1 = start->next;
	listint_t *temp2 = end->prev;

	if (temp1 != NULL)
		temp1->prev = end;
	if (temp2 != NULL)
		temp2->next = start;

	start->prev = temp2;
	end->next = temp1;
	start->next = end;
	end->prev = start;

	if (*list == end)
		*list = start;
	print_list(*list);
}
/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail shaker sort
 * @list: input list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *start = NULL, *end = NULL;

	if ((!list) || (!(*list)) || (!(*list)->next))
		return;
	do {
		while (check->next)
		{
			if (check->n > check->next->n)
				swap_nodes(check->next, check, list);
			else
				check = check->next;
		}
		end = check;
		while (check->prev != start)
		{
			if (check->n < check->prev->n)
				swap_nodes(check, check->prev, list);
			else
				check = check->prev;
		}
		start = check;
	} while (start != end);
}
