#include "sort.h"

/**
 * selection_sort - trie un tableau d'entiers dans l'ordre croissant
 *                  en utilisant l'algorithme de tri par sélection
 *
 * @array: tableau d'entiers à trier
 * @size: taille du tableau
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			int tmp = array[i];

			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
