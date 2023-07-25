#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int min_val;
	size_t a_idx, b_idx, trav_idx;

	if (array == NULL)
	{
		return;
	}
	for (a_idx = 0; a_idx < size; a_idx++)
	{
		min_val = array[a_idx];
		trav_idx = a_idx;

		for (b_idx = a_idx + 1; b_idx < size; b_idx++)
		{
			if (min_val > array[b_idx])
			{
				trav_idx = b_idx;
				min_val = array[b_idx];
			}
		}
		if (trav_idx != a_idx)
		{
			array[trav_idx] = array[a_idx];
			array[a_idx] = min_val;
			print_array(array, size);
		}
	}
}
