#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{

	size_t i, j;
	int tmp, flag;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				flag = 1;
			}
		}
		if (flag)
			print_array(array, size);
	}
}
