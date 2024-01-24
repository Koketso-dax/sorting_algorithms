#include "sort.h"

/**
 * shell_sort - sorts array using shell_sort (Knuth sequence)
 * @array: input array
 * @size: array size
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t x, y;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval > 0)
	{
		for (x = interval; x < size; x++)
		{
			temp = array[x];
			for (y = x; y >= interval && array[y - interval] > temp; y -= interval)
			{
				array[y] = array[y - interval];
			}
			array[y] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
