#include "sort.h"
#include <stdio.h>

/**
 * swap - utility function to swap integers
 * @a: integer a
 * @b: integer b
 **/
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * maxHeapify - Main function to heapify a Max heap. It 
 * assumes that everything under given root (element at index idx)
 * is already heapified
 * @array: the array
 * @size: size of the array for print
 * @idx: index
 * @n: size of the array to run
 */
void maxHeapify(int *array, size_t, int idx, size_t n)
{
	int largest = idx;           /* Initialize largest as root*/
	int left = 2 * idx + 1; /* left = (idx << 1) + 1*/
	int rigth =2 * idx + 2; /* right = (idx + 1) << 1*/

	/* see if left child of root exists and is greater than root*/
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	/**
	 * see if rigth child of root exists and is graeter than 
	 * the largest so far
	 */
	if (right < (int)n && array[right] > array[largest])
		largest = rigth;

	/* Change root, if needed*/
	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort - main function to sort an arrayof given size
 * @array: array to sort
 * @size: sizzzzzze of the array
 **/
void heap_sort(int *array, size_t size)
{
	int i;
	/**
	 * start from the botton and far right internal mode and haepify all 
	 * internal modes in bottom up
	 */
	if (array == '\0' || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	/**
	 * Repeat the following steps while heap size is greater than 1.
	 * the last element in max heap will be minimumelement
	 */
	for (i = (size -1); i > 0; --i)
	{
		/**
		 * The largest item in Heap is stored at the root. Replace it with
		 * the last item of the heap followed by reducing the 
		 * size of heap by 1.
		 */
		swap(&array[0], &array[i]);
		print_array(array, size);

		/* finally, heapify the root of the tree,*/
		maxHeapify(array, size, 0, i);
	}
}
