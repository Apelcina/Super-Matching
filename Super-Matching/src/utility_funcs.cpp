#include <iostream>

void swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int partition(int* arr, int low, int high)
{
	int j = low;
	
	int pivot = arr[high];
	
	for(int i = low; i < high; i++)
		if(arr[i] <= pivot)
		{
			swap(arr, i, j);
			j++;
		}
			
	swap(arr, j, high);
	return j;
}


void quickSort(int* arr, int low, int high)
{
	int pi;
	if (low < high)
	{
		pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void binarySearch(int* arr, int size, int target)
{
	int low = 0;
	int high = size - 1;
	int mid;
	
	while(low < high)
	{
		mid = (low + high) / 2;
		if(arr[mid] == target)
			std::cout << "Quicksort binary search found " << arr[mid] << " in both arrays." << std::endl;
		else if(arr[mid] <= target)
			low = mid + 1;
		else
			high = mid - 1;
	}
}
