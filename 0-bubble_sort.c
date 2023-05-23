#include "sort.h"

/**
 * bubble_sort - Tri un tableau d'entiers par ordre croissant en utilisant
 *               l'algorithme de tri à bulles
 * @array: Le tableau d'entiers à trier
 * @size: Taille du tableau
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int change;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		change = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				change = 1;

				print_array(array, size);
			}
		}

		if (change == 0)
			break;
	}
}
