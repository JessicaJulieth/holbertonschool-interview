#include "search_algos.h"

/**
  * print_array - Print
  * @arr: Array to print
  * @init: Start of print
  * @end: End print
  */

void print_array(int *arr, int init, int end)
{
	int i = 0;

	printf("Searching in array: ");
	while (init <= end)
	{
		if (i > 0)
			printf(", ");
		i = init++;
		printf("%d", arr[i++]);
	}
	printf("\n");
}


/**
  * rec_search - recursively search using binary algo
  * @arr: array to search
  * @x: left most value
  * @y: right most value
  * @val: value to search
  *
  * Return: index or -1 if not found
  */

int rec_search(int *arr, int x, int y, int val)
{
	int mid;

	if (y >= x)
	{
		mid = x + (y - x) / 2;
		print_array(arr, x, y);

		if (arr[mid] == val)
		{
			if (mid != 0 && arr[mid - 1] == val)
				return (rec_search(arr, x, mid, val));
			return (mid);
		}

		if (arr[mid] > val)
			return (rec_search(arr, x, mid, val));

		return (rec_search(arr, mid + 1, y, val));
	}
	return (-1);
}


/**
  * advanced_binary - Print message
  * @array: Array to find
  * @size: Array
  * @value: Value to looking for
  *
  * Return: Index
  */

int advanced_binary(int *array, size_t size, int value)
{
	if (array && size)
		return (rec_search(array, 0, (int)size - 1, value));
	return (-1);
}