#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 *               using the bubble sort algotithm.
 * @array: The array to be sorted.
 * @size: the size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	do {
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					swapped = 1;
					print_array(array, size);
				}
			}
		}
	} while (swapped);
}
