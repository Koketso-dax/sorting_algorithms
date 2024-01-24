#include "sort.h"

/**
 * swap - will swap 2 array elements
 * @a: pointer to first element
 * @b: pointer to second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - implements the Lomuto partiton scheme to split an array
 * @array: input array
 * @low: first index
 * @high: pivot index
 * @size: array size
 * Return: [] index
 */
int partition(int array[], int low, int high, size_t size)
{
	int x = low - 1, y;

	for (y = low; y <= high - 1; y++)
	{
		if (array[y] < array[high])
		{
			x++;
			if (x < y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	if (array[x + 1] > array[high])
	{
		swap(&array[x + 1], &array[high]);
		print_array(array, size);
	}
	return (x + 1);
}

/**
 * qs_helper - will apply the qs and partition algorithm recursively
 * @array: input array
 * @low: first value
 * @high: last value
 * @size: array size
 */
void qs_helper(int array[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		qs_helper(array, low, pi - 1, size);
		qs_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - will parse array and implement qs algorithm
 * @array: input array
 * @size: array size
 */
void quick_sort(int array[], size_t size)
{
	if (array == NULL || size < 2)
		return;
	qs_helper(array, 0, size - 1, size);
}
