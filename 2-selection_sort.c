#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm
 *
 * @list: double pointer to the head of the list
 */
void selection_sort(int *array, size_t size)
{
	listing_t *curr, *prev_node, *next_node;

	if (!list || !*list || !(*list)-next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		prev_node = curr->prev;
		next_node = curr->next;

		while (prev_node && prev_node->n > curr->n)
		{
			if (prev_node->prev)
				prev_node->prev->next = curr;
			else
				*list = curr;

			curr->prev = prev_node->prev;
			prev_node->next = next_node;

			prev_node->prev = curr;
			curr->next = prev_node;

			prev_node = curr->prev;

			print_list(*list);
		}

		curr = next_node;
	}
}
