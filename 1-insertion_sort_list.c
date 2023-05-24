#include "sort.h"
/**
 * insertion_sort_list - Sorts a double-chained list using the insertion sort algorithm.
 *
 * @list: A pointer to a pointer to the first element in the list.
 *
 * Description :
 * This function sorts a double-chained list using the insertion sort algorithm.
 * It traverses the list by comparing each element with the previous elements and rearranges the links
 * Rearrange the links accordingly to insert each element in its correct place.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;
	listint_t *temp = NULL;

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			print_list(*list);
		}

		current = current->next;
	}
}
