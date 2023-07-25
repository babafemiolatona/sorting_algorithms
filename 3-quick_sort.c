#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @i: first element
 * @j: second element
 */

void swap(int *i, int *j)
{
	int tmpVar = 0;

	tmpVar = *i;
	*i = *j;
	*j = tmpVar;
}

/**
 * partition - partitions the input array into two sub-arrays
 * @array: pointer to the array of intgers to be sorted
 * @start_idx: starting index of the partition
 * @pvt_idx: index of the pivot element
 * @size: size of the array
 * Return: new position of the pivot element after partitioning
 */

size_t partition(int *array, size_t start_idx, size_t pvt_idx, size_t size)
{
	size_t i;

	for (i = start_idx; i < pvt_idx; i++)
	{
		if (array[i] < array[pvt_idx])
		{
			if (i != start_idx)
			{
				swap(&array[start_idx], &array[i]);
				print_array(array, size);
			}
			start_idx++;
		}
	}
	if (array[start_idx] > array[pvt_idx])
	{
		swap(&array[start_idx], &array[pvt_idx]);
		pvt_idx = start_idx;
		print_array(array, size);
	}
	return (pvt_idx);
}

/**
 * sort - uses recursion to sort smaller sub-arrays by calling
 * the partition function
 * @array: pointer to the array of integers to be sorted
 * @i: starting index of the current sub-array to be sorted
 * @j: ending index of the current sub-array to be sorted
 * @size: size of the array
 */

void sort(int *array, size_t i, size_t j, size_t size)
{
	size_t pvt_idx;

	if (j == 0 || j <= i)
	{
		return;
	}
	pvt_idx = partition(array, i, j, size);
	if (pvt_idx != 0 && pvt_idx > i)
	{
		sort(array, i, pvt_idx - 1, size);
	}
	if (pvt_idx < size - 1)
	{
		sort(array, pvt_idx + 1, j, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the quick sort algorithm
 * @array: pointer to the array of integers to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0 || size == 1)
	{
		return;
	}
	sort(array, 0, size - 1, size);
}
