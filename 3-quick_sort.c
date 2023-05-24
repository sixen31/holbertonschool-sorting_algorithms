#include "sort.h"

/**
 * swap - Échange les valeurs de deux entiers.
 * @a: Pointeur vers le premier entier.
 * @b: Pointeur vers le deuxième entier.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Effectue le partitionnement pour le tri rapide.
 * @array: Tableau d'entiers à trier.
 * @low: Indice de début de la partition.
 * @high: Indice de fin de la partition.
 * 
 * Return: L'indice du pivot après partitionnement.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_helper - Fonction auxiliaire pour effectuer le tri rapide de manière récursive.
 * @array: Tableau d'entiers à trier.
 * @low: Indice de début de la partition.
 * @high: Indice de fin de la partition.
 */
void quick_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int partition_index = partition(array, low, high);

		quick_sort_helper(array, low, partition_index - 1);
		quick_sort_helper(array, partition_index + 1, high);
	}
}

/**
 * quick_sort - Effectue le tri rapide sur un tableau.
 * @array: Tableau d'entiers à trier.
 * @size: Taille du tableau.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1);
}
