#include "sort.h"

/**
 * _swap - swaped 2 values.
 * @array: the array for swap him values.
 * @i: First index
 * @j: Second index
 * @r_size: The size constant for print
 * Return: Nothing
 */
void _swap(int *array, int i, int j, const int r_size)
{
	int tmp;
	(void) r_size;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, (size_t)r_size);
	}
}

/**
 * _largest - Find the largest number btween the layers
 * @array: The array for sort
 * @size: The menor element
 * @i: The largest.
 * @r_size: The size for print in swap
 * Return: Nothing.
 */
void _largest(int *array, size_t size, int i, const int r_size)
{
	int largest = i;
	int lft = (2 * i) + 1;
	int rgt = (2 * i) + 2;

	if (lft < (int)size && array[lft] > array[largest])
		largest = lft;

	if (rgt < (int)size && array[rgt] > array[largest])
		largest = rgt;

	if (largest != i)
	{
		_swap(array, i, largest, r_size);
		_largest(array, size, largest, r_size);
	}
}

/**
 * heap_sort - Call largest while exist layers
 * @array: The array that generate the layers
 * @size: Size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	const int r_size = (const int)size;
	int i;

	if (size < 2 || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		_largest(array, size, i, r_size);

	for (i = size - 1; i >= 0; i--)
	{
		_swap(array, 0, i, r_size);
		_largest(array, i, 0, r_size);
	}
}
