#include "sort.h"

/**
 * _swap - swaps two values in an array
 *
 * @array: data to sort
 * @i: first value
 * @j: second value
 * @size: size of data
 *
 * Return: No Return
 */
void _swap(int *array, int i, int j, int size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * partition - sorts a partition of data in relation to a pivot
 *
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 * Return: New Pivot
 */
int partition(int *array, int min, int max, size_t size)
{
	int i, j, pivot = array[max];

	for (i = min, j = max; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i < j)
			_swap(array, i, j, size);
		else
			return (i);
	}
}

/**
 * quicksort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 *
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 * Return: No Return
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int p;

	if (min < max)
	{
		p = partition(array, min, max, size);
		quicksort(array, min, p - 1, size);
		quicksort(array, p, max, size);
	}
}

/**
 * quick_sort_hoare -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Hoare partition scheme
 *
 * @array: data to sort
 * @size: size of data
 *
 * Return: No Return
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
