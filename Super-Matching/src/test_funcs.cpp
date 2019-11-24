#include <iostream>

#include "utility_funcs.h"

void testIterative(int* arr1, int* arr2, size_t size)
{
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			if (arr1[i] == arr2[j])
				std::cout << "Unsorted iterative search found " << arr1[i] << " in both arrays." << std::endl;
}

void testBinarySearch(int* arr1, int* arr2, int size)
{
	quickSort(arr1, 0, size - 1);
	
	for(int i = 0; i < size; i++)
		binarySearch(arr1, size, arr2[i]);
}
