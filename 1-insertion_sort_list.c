#include "sort.h"
/**
* insertion_sort_list - Sorts a doubly linked list using insertion sort
* @list: Double pointer to the beginning of the list
* The list is sorted in ascending order.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
    listint_t *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

		current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
	
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			if (temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			temp->prev->next = temp->next;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
			{
				*list = temp;
			} else
			{
				temp->prev->next = temp;
			}

			print_list(*list);
		}
		current = current->next;
	}
}

