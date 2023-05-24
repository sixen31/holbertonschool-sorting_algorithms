#include "sort.h"

/**
 *Fonction de swap pour échanger les valeurs de deux entiers.
 *@param a Pointeur vers le premier entier.
 *@param b Pointeur vers le deuxième entier.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *Fonction de partitionnement pour le tri rapide.
 *@param array Tableau d'entiers à trier.
 *@param low Indice de début de la partition.
 *@param high Indice de fin de la partition.
 *@return L'indice du pivot après partitionnement.
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
 *Fonction auxiliaire pour effectuer le tri rapide de manière récursive.
 *@param array Tableau d'entiers à trier.
 *@param low Indice de début de la partition.
 *@param high Indice de fin de la partition.
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
 *Fonction principale pour effectuer le tri rapide sur un tableau.
 *@param array Tableau d'entiers à trier.
 *@param size Taille du tableau.
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1);
}
