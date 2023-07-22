#include "sort.h"

/**
 * swap - swaps two items in an array.
 * @array: input array
 * @l: index of the left item.
 * @r: index of the right item.
 */
void swap(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * quick_sort_lomuto - sorts a part of an array
 * using the Lomuto partition scheme.
 * @array: input array
 * @low: first index of array
 * @high: last index of array
 * @size: number of items in the array.
 */
void quick_sort_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(array, i, high);
		print_array(array, size);
	}
	if (i - low > 1)
		quick_sort_lomuto(array, low, i - 1, size);
	if (high - i > 1)
		quick_sort_lomuto(array, i + 1, high, size);
}

/**
 * quick_sort - sorts an array of integers using the
 * quick sort algorithm
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_lomuto(array, 0, size - 1, size);
	}
}
