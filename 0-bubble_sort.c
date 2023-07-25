#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int tmpVar;
	size_t idx, num;

	if (size < 2)
	{
		return;
	}
	for (num = 0; size - 1 != num;)
	{
		num = 0;
		for (idx = 0; idx + 1 != size; idx++)
		{
			if (array[idx + 1] < array[idx])
			{
				tmpVar = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = tmpVar;
				print _array(array, size);
			}
			else
			{
				num++;
			}
		}
	}
}
