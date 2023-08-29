#include "sort.h"

/**
* low_high - finds the low and high in the array. Helper function
* for quick_sort.
* @array: array.
* @size: size of the array.
* @index: starting index.
* @p_index: index of the pivot.
* @ret_array: pointer to array.
* Return: void.
* index 0: the low value.
* index 1: the high value.
* index 2: the low's index.
* index 3: the high's index.
*/
void low_high(int *array, size_t size, int index, int p_index, int *ret_array)
{
size_t i, j;
int pivot = array[p_index];

for (i = index + 1; i < size; i++)
{
if (array[i] <= pivot)
{
ret_array[0] = array[i];
ret_array[2] = i;
break;
}
}
for (j = 0; j < size; j++)
{
if (array[j] > pivot)
{
ret_array[1] = array[j];
ret_array[3] = j;
break;
}
}
}
/**
* set_pivot - a function that finds the correct placement of
* the pivot.
* @array: the array.
* @size: size of the array.
* @p_index: index of the pivot.
* Return: new index.
*/
int set_pivot(int *array, size_t size, int p_index)
{
int value[4] = {-1, -1, -1, -1}, i = -1;

while (1 == 1)
{
low_high(array, size, i, p_index, value);
/*check if the pivot is correctly placed*/
if (value[2] <= p_index && (value[3] == -1 ||
value[3] > p_index))
{
return (p_index);
}
/*Check if high comes before low*/
if (value[3] < value[2] && value[3] != -1)
{
/*swap high and low values*/
if (value[2] == p_index)
p_index = value[3];
array[value[3]] = value[0];
array[value[2]] = value[1];
i = -1;
print_array(array, size);
continue;
}
i++;
}
}
/**
* quick_sort - a function that sorts an array of integers in
* ascending order using the Quick sort algorithm.
* @array: array to be sorted.
* @size: The size of the array.
* Return: void
*/
void quick_sort(int *array, size_t size)
{
int i, p_index;

if (array == NULL || size <= 1)
return;
i = size - 1;
while (i > 0)
{
if (array[i] < array[i - 1])
{
p_index = i;
set_pivot(array, size, p_index);
i = size - 1;
continue;
}
else
i--;
}
}
