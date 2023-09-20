#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	while (list != NULL)
	{
		printf("%d", list->n);
		if (list->next != NULL)
			printf(", ");
		list = list->next;
	}
	printf("\n");
}
