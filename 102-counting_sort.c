#include "sort.h"
#include <stdio.h>
/**
 * _bigest -  Give me the largest number in a array of integers
 * @array: The Int array
 * @size: Size of array
 * Return: The largest number
 */
int _bigest(int *array, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < array[i])
			k = array[i];
	}

	return (k);
}
/**
 * _memset -  Create a integer array and set each space in 0
 * @size: Size of array
 * Return: The integer array
 */
int *_memset(int size)
{
	int *ptr = NULL;
	int i;

	ptr = malloc((size) * sizeof(int));

	for (i = 0; i < size; i++)
		ptr[i] = 0;

	return (ptr);
}
/**
 * counting_sort - sort an array with the counting sort algorithm
 * @array: The Int array
 * @size: Size of array
 * Return: The sorted list
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int k = 0;
	int *ptr = NULL, *sort_ar = NULL;

	if (size < 2)
		return;
	/*Know the largest number in the array*/
	k = _bigest(array, size);
	/*Make the help array*/
	ptr = _memset(k + 1);
	if (!ptr)
		return;
	/*Set the values for sorting*/
	for (i = 0; i < size; i++)
		for (j = 0; (int)j < k + 1; j++)
			if ((int)j == array[i])
				ptr[j] += 1;
	/*Modificate the count in the array*/
	for (i = 0; (int)i < k; i++)
		ptr[i + 1] = ptr[i] + ptr[i + 1];
	print_array(ptr, k + 1);
	/*Create the sort array*/
	sort_ar = malloc(size * sizeof(int));
	if (!sort_ar)
	{
		free(ptr);
		return;
	}

	for (i = 0; i < size; i++)
	{
		sort_ar[ptr[array[i]] - 1] = array[i];
		ptr[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = sort_ar[j];

	free(sort_ar);
	free(ptr);
}
