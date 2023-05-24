#include "sort.h"

/*
 * insertion_sort_list - Function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *@list: Double pointer to the head of the doubly linked list.
 *
 * Description: This function implements the Insertion sort algorithm to sort
 * a doubly linked list in ascending order. It takes the double pointer to the
 * head of the list as input and modifies the list in place.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;	

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;

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
