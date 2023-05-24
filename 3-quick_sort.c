#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	int pivot = array[size - 1];
	size_t i = 0;

	for (size_t j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}

	int temp = array[i];
	array[i] = array[size - 1];
	array[size - 1] = temp;

	for (size_t k = 0; k < size; k++)
	{
		printf("%d ", array[k]);
	}
	printf("\n");

	quick_sort(array, i);
	quick_sort(array + i + 1, size - i - 1);
}
