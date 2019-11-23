#include <iostream>

int testIterative(unsigned int* arr1, unsigned int* arr2, size_t size)
{
	int count;
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			if (arr1[i] == arr2[j])
			{
				std::cout << "Unsorted iterative search found " << arr1[i] << " in both arrays." << std::endl;
				count++;
				std::cout << "i: " << i << std::endl;
				std::cout << "j: " << j << std::endl;
			}
	return count;
}