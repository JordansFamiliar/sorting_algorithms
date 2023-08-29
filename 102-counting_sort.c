#include "sort.h"

/**
 * set_count_array - a helper function that sets the count
 * array for the counting sort algorithm.
 * @array: array to be sorted.
 * @k: size of the count array.
 * @size: size of the input array.
 * Return: a pointer to the count array.
 */
int *set_count_array(int *array, size_t k, size_t size)
{
	int *count = malloc(sizeof(int) * k), freq;
	size_t i, j;

	for (i = 0; i < k; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		freq = 1;
		for (j = 0; j < size; j++)
		{
			if (j != i && array[j] == array[i])
				++freq;
		}
		count[array[i]] = freq;
	}
	for (i = 0; i < k; i++)
	{
		if (i != 0)
			count[i] += count[i - 1];
	}
	print_array(count, k);
	return (count);
}
/**
 * counting_sort - a function that sorts an list of integers
 * using the counting sort algorithm.
 * @array: array of integers to be sorted.
 * @size: size of the array.
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	int val = 0, *count = NULL;
	size_t i, k = 0;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)k)
			k = array[i];
	}
	k += 1;
	/* call set_count_array */
	count = set_count_array(array, k, size);
	for (i = 0; i < k; i++)
	{
		if (count[i] > val)
		{
			array[count[i] - 1] = i;
			val = count[i];
		}
	}
	free(count);
}
