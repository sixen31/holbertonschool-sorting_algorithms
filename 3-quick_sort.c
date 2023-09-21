#include "sort.h"

void quick_sort_helper(int *array, int low, int high, size_t size);

/**
 * swap - Swaps two integers in an array
 *
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme
 *
 * @array: Array to be partitioned
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 *
 * Return: Index of the pivot element
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
 * quicksort - Quick sort algorithm
 *
 * @array: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
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
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	int pi = partition(array, 0, size - 1, size);

	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, pi - 1, size);
	quick_sort_helper(array, pi + 1, size - 1, size);
}

/**
 * quick_sort_helper - Helper function for quick_sort
 *
 * @array: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}
