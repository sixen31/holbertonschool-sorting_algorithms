#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next_node = current->next;
		prev_node = current->prev;
		while (prev_node && prev_node->n > current->n)
		{
			prev_node->next = current->next;
			if (current->next)
				current->next->prev = prev_node;
			current->next = prev_node;
			current->prev = prev_node->prev;
			prev_node->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
			prev_node = current->prev;
		}
		current = next_node;
	}
}
