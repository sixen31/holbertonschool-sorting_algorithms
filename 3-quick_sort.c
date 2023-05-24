#include "sort.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return i + 1;
}

void quick_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int partition_index = partition(array, low, high);
		quick_sort_helper(array, low, partition_index - 1);
		quick_sort_helper(array, partition_index + 1, high);
	}
}

void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1);
}
