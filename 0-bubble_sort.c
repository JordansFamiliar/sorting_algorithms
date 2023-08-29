#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order using the
 * Bubble sort algorithm.
 * @array: Array to be sorted
 * @size: The size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size == 0)
		return;

	for (j = 0; j < size - 1; j++)
	{
		for (i = 0; i < size - j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
