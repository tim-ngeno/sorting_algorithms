#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: input array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int swapped;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < (size - 1) - i; j++)
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

		if (swapped == 0)
			break;
	}

}
