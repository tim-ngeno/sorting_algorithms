#include "sort.h"

/**
 * counting_sort - sorts an array of integers using
 * the Counting Sort algorithm
 * @array: the input array
 * @size: size of the array
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max_element = 0, j;
	int *count_arr, *output_arr;

	if (size <= 1)
		return;
	/* Find max element of the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_element)
			max_element = array[i];
	}
	/* Create the counting array */
	count_arr = malloc(sizeof(int) * (max_element + 1));
	if (count_arr == NULL)
		return;
	/* Initialize count_arr to zero, count elems and accumulatevalues */
	for (j = 0; j <= max_element; j++)
		count_arr[j] = 0;
	for (i = 0; i < size; i++)
		count_arr[array[i]]++;
	for (j = 1; j <= max_element; ++j)
		count_arr[j] += count_arr[j - 1];
	print_array(count_arr, max_element + 1);
	/* arrange elements in ascending order */
	output_arr = malloc(sizeof(int) * size);
	if (output_arr == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = size - 1; i > 0; i--)
	{
		output_arr[count_arr[array[i] - 1]] = array[i];
		count_arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_arr[i];
	free(count_arr);
	free(output_arr);
}
