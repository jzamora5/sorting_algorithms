#include <stdlib.h>
#include "sort.h"
#include "sort.h"

/**
 * getMax - obtains Max Value of Array
 *
 * @array: array of data to be sorted
 * @size: size of array
 *
 * Return: No Return
 */
int getMax(int *array, int size)
{
	int max, i;

	max = array[0];
	for (i = 1; i < size; i++)
	      	if (array[i] > max)
			max = array[i];
	return (max);
}
/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void radix_sort(int *array, size_t size)
{

	int bckt[10][10], bcktC[10], i, j, k, r, limit, divs, max, pass, s;

	if (size < 2)
		return;

	limit = 0, divs = 1;
	s = size;
	max = getMax(array, size);

	while (max > 0)
		limit++, max /= 10;

	for (pass = 0; pass < limit; pass++)
	{
		for (i = 0; i < 10; i++)
			bcktC[i] = 0;

		for (i = 0; i < s; i++)
		{
			r = (array[i] / divs) % 10;
			bckt[r][bcktC[r]] = array[i];
			bcktC[r] += 1;
		}

		for (i = 0, k = 0; k < 10; k++)
			for (j = 0; j < bcktC[k]; j++)
				array[i] = bckt[k][j], i++;
		divs *= 10;
		print_array(array, size);
	}
}
