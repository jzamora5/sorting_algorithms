#include "sort.h"
#include <stdio.h>

/**
 *
 *
 *
 *
 */
void printcheck(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 *
 *
 *
 *
 */
void _swap(int *array, int i, int j, int dir/* , int size, const int r_size */)
{
	int tmp;

	if (dir == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		/* if (dir == 1) */
		/* { */
		/* 	printf("Result [%d/%d] (UP)\n", size, r_size); */
		/* 	printcheck(array, i, j); */
		/* } */
		/* if (dir == 0) */
		/* { */
		/* 	printf("Result [%d/%d] (DOWN)\n", size, r_size); */
		/* 	printcheck(array, i, j); */
		/* } */
	}
}
/**
 *
 *
 *
 *
 */
void bitonic_merge(int *array, int low, int size, int dir, const int r_size)
{
	int k = size, i;

	if (size > 1)
	{
		k = size / 2;

		for (i = low; i < low + k; i++)
			_swap(array, i, i + k, dir/*, size, r_size */);

		bitonic_merge(array, low, k, dir, r_size);
		bitonic_merge(array, low + k, k, dir, r_size);
	}
}
/**
 *
 *
 *
 *
 */
void _sort(int *array, int low, int size, int dir, const int r_size)
{
	int k = size;

	if (size > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP)\n", size, r_size);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN)\n", size, r_size);
		printcheck(array, low, low + k - 1);

		k = size / 2;
		_sort(array, low, k, 1, r_size);

		_sort(array, low + k, k, 0, r_size);

		bitonic_merge(array, low, size, dir, r_size);
	}
}
/**
 *
 *
 *
 *
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	_sort(array, 0, (int)size, up, r_size);
}
