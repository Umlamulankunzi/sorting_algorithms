#include "sort.h"


/**
 * swap_elements - swaps the positions of two elements in an array
 * @array: pointer to the array
 * @index1: index of the first element
 * @index2: index of the second element
 */
void swap_elements(int *array, int index1, int index2)
{
	int tmp = array[index1];

	array[index1] = array[index2];
	array[index2] = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order using the
 *              Shell sort algorithm with the Knuth sequence
 * @array: pointer to the array
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = 3 * gap + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
			{
				swap_elements(array, j, j - gap);
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
