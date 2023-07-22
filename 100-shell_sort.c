#include "sort.h"

/**
 * shell_sort - sort an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: the input array
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	unsigned int i, j, gap = 0;

	if (size < 2)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
			for (j = i; j >= gap && array[j - gap] >
				     array[j]; j -= gap)
			{
				temp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = temp;
			}
		gap /= 3;
		print_array(array, size);
	}
}
