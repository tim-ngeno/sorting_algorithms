#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, min;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min])
				min = b;
		}
		if (a != min)
		{
			tmp = array[a];
			array[a] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}

