#include "sort.h"

/**
 * selection_sort - sorts array and prints result after each interation
 * @array: input array
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, min, temp, swap;

	if (array == NULL)
		return;

	for (x = 0; x < size; x++)
	{
		min = x;
		swap = 0;

		for (y = x; y < size; y++)
		{
			if (array[y] < array[min])
			{
				min = y;
				swap = 1;
			}
		}
		if (swap == 1)
		{
			temp = array[min];
			array[min] = array[x];
			array[x] = temp;
			print_array(array, size);
		}
	}

}
