#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 *                 Counting sort algorithm.
 * @array: pointer to array of integers to sort.
 * @size: size of array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = 0;
	size_t i;

	if (!array || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a count array of size max + 1 and initialize all values as 0 */
	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);
	if (!count || !output)
		return;

	for (i = 0; i <= (size_t)max; i++)
	{
		count[i] = 0;
	}

	/* Store the count of each element in the count array */
	for (i = 0; i < size; i++)
	{
		count[array[i]] += 1;
	}

	/* Modify the count array by adding the previous counts */
	for (i = 1; i <= (size_t)max; i++)
	{
		count[i] += count[i - 1];
	}

	/* Output each object from the input sequence followed by */
	/* decreasing its count by 1 */
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	/* Print the sorted array */
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	print_array(count, max + 1);

	free(count);
	free(output);
}
