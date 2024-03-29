#include "sort.h"

/**
 * bubble_sort - will sort an array using the bubble sort algorithm
 * @array: input array
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int temp = 0;

	if (array == NULL || size < 2)
		return;

	for (x = size; x > 0; x--)
	{
		for (y = 0; y < x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
