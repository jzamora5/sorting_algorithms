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
	int max = array[0];

	for (int i = 1; i < size; i++)
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

	int bucket[10][10], bucket_cnt[10];
	int i, j, k, r, limit = 0, divs = 1, max, pass, s;

	if (size < 2)
		return;

	s = size;
	max = getMax(array, size);

	while (max > 0)
		limit++, max /= 10;

	for (pass = 0; pass < limit; pass++)
	{
		for (i = 0; i < 10; i++)
			bucket_cnt[i] = 0;

		for (i = 0; i < s; i++)
		{
			r = (array[i] / divs) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}

		i = 0;
		for (k = 0; k < 10; k++)
			for (j = 0; j < bucket_cnt[k]; j++)
				array[i] = bucket[k][j], i++;
		divs *= 10;
		print_array(array, size);
	}
}
