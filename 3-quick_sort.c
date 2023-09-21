#include "sort.h"

/**
 * swap - Échange deux entiers dans un tableau
 *
 * @a: Premier entier
 * @b: Deuxième entier
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Schéma de partitionnement Lomuto
 *
 * @array: Tableau à partitionner
 * @low: Indice de début de la partition à trier
 * @high: Indice de fin de la partition à trier
 * @size: Taille du tableau
 *
 * Return: Indice de l'élément pivot
 */
int partition(int *array, int low, int high, size_t size)
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
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * quicksort - Algorithme de tri rapide
 *
 * @array: Tableau à trier
 * @low: Indice de début de la partition à trier
 * @high: Indice de fin de la partition à trier
 * @size: Taille du tableau
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pi = partition(array, low, high, size);

	if (low < high)
	{
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Trie un tableau d'entiers par ordre croissant en utilisant
 * l'algorithme de tri rapide
 *
 * @array: Tableau à trier
 * @size: Taille du tableau
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
