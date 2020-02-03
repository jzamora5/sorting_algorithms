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
 * countaux - Auxiliary function of cSort
 *
 * @array: array of data to be sorted
 * @max: max value in array
 * @place: Less significant digit
 * @size: size of data
 * @output: counting sort output
 *
 * Return: No Return
 */
void countaux(int *array, int max, int place, int size, int *output)
{

	int count[max + 1];

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (int i = 0; i < size; i++)
		array[i] = output[i];

}
/**
 * cSort - counting Sort
 *
 * @array: array of data to be sorted
 * @size: size of data
 * @place: Less significant digit
 *
 * Return: No Return
 */
void cSort(int *array, int size, int place)
{
	int output[size + 1];
	int max = (array[0] / place) % 10;

	for (int i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	countaux(array, max, place, size, output);
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
	int max;

	if (size < 2)
		return;

	max = getMax(array, size);

	for (int place = 1; max / place > 0; place *= 10)
	{
		cSort(array, size, place);
		print_array(array, size);
	}
}
