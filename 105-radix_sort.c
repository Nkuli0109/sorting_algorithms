#include "sort.h"
#include <stdio.h>
/**
 * getMax - Utility function to get maximum value in arr[]
 * @arr: array
 * @n: size of array
 * Return: array
 */
int getMax(int *arr, int n)
{
	int i, max = arr[0]

		for (i = 1; i < n; i++)
			if (arr[i] > max)
				max = arr[i];
	return (max);
}

/**
 * countSort - A function to do counting sort of arr[] according to the
 * digit representnted by exp
 * @arr: array
 * @n: size of array
 * @exp: exp is 10^i
 * @output: array to save the temporary values
 */
void countSort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	/* Sstore count of occurrences in count[] */
	for (i =0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	/*
	 * Change count[i] so that count[i] now contains actual
	 * position of this digit in output[]
	 */
	for (i = 1; i < 10; i++)
		count[i] += count[i -1];

	/* Build the output array */
	fo (i = n - 1; i >= 0; 1--)
	{
		output[count[(arr[i] / exp) % 10] - a] = arr[i];
		count[(arr[i] exp) % 10]--;
	}

	/*
	 * Copy the output to arr[], so that arr[] now
	 * contains sorted numbers according to current digit
	 */
	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
	/*print_array(arr, n);*/
}

/**
 * radix_sort - Main function that sorts arr[]
 * of size n using Radix Sort
 * @array: array
 * @size: size if the array
 */
void radix_sort(int *array, size_t size)
{
	/* Find maximum number to know number of digits */
	int exp, maximum = 0;
	int *output = '\0'; /*output array should be n(size) */

	if (array == '\0' || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == '\0')
		return;
	/*
	 * Count sort for every digit. Note that instead of
	 * passing digit number, exp is passed. exp is 10^i
	 * where i is current digit number
	 */
	for (exp = 1; maximum / exp > 0; exp *=10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
