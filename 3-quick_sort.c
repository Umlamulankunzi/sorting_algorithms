#include "sort.h"


/**
 * swap_ints - swaps the positions of two integers in an array
 * @array: pointer to the array
 * @index1: index of the first integer
 * @index2: index of the second integer
 */
void swap_ints(int *array, ssize_t index1, ssize_t index2)
{
	int tmp = array[index1];

	array[index1] = array[index2];
	array[index2] = tmp;
}



/**
 * lomuto_partition - partitions an array using the Lomuto partition scheme
 * @array: pointer to the array
 * @first: index of the first element
 * @last: index of the last element
 * @size: size of the array
 * Return: position of the last element sorted
 */
ssize_t lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap_ints(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap_ints(array, current, last);
		print_array(array, size);
	}
	return (current);
}


/**
 * quicksort - sorts an array using the QuickSort algorithm
 * @array: pointer to the array
 * @first: index of the first element
 * @last: index of the last element
 * @size: size of the array
 */
void quicksort(int *array, ssize_t first, ssize_t last, size_t size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);
		quicksort(array, first, position - 1, size);
		quicksort(array, position + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
