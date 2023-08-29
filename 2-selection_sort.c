#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in
 * ascending order using the selection sort algorithm.
 * @array: array to be sorted.
 * @size: size of the array.
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
        size_t i, j, index = 0;
        int min, change = 0;

        if (array == NULL || size == 0)
                return;
        for (i = 0; i < size - 2; i++)
        {
                min = array[i];
                for (j = i; j < size; j++)
                {
                        if (array[j] < min)
                        {
                                min = array[j];
                                index = j;
                                change = 1;
                        }
                }
                if (change == 1)
                {
                        array[index] = array[i];
                        array[i] = min;
                        print_array(array, size);
                }
                change = 0;
        }
}
