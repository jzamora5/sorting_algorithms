#include <stdlib.h>
#include "sort.h"
#include <stdio.h>
/**
 * bubble_sortLSD - bubble sort based off LSD
 *
 * @array: array of data to be sorted
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void bubble_sortLSD(int *array, int size, int lsd)
{
	int i, j, tmp, divs = 1;

	for (i = 1; i < lsd; i++)
		divs *= 10;

	for (i = 0; i <= size - 1; i++)
	{
		for (j = 0; j <= size - 2; j++)
		{
			if ((array[j] / divs % 10) > (array[j + 1] / divs % 10))
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}
/**
 * rsort - recursive radix sort with bubble sort
 *
 * @array: array of data to be sorted
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void rsort(int *array, int size, int lsd)
{
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, num, divs = 1;

	for (i = 1; i < lsd; i++)
		divs *= 10;

	for (i = 0; i < size; i++)
	{
		num = array[i] / divs % 10;
		carr[num] += 1;
	}

	if (carr[0] == size)
		return;

	bubble_sortLSD(array, size, lsd);
	print_array(array, size);
	rsort(array, size, lsd + 1);

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
	int lsd = 1;

	if (size < 2)
		return;

	rsort(array, size, lsd);
}
