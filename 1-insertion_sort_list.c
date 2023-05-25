#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: pointer to list head pointer
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *current, *insertion_point;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current->prev;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			insertion_point->next = current->next;
			if (current->next != NULL)
				current->next->prev = insertion_point;

			current->prev = insertion_point->prev;
			current->next = insertion_point;
			insertion_point->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			insertion_point = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
