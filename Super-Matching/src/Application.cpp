
#include <iostream>
#include <random>
#include <time.h>
#include <thread>
#include <chrono>
#include <cstring>

#include "m1-iterative.h"

/* SET_SIZE represents size of our data set */
#define SET_SIZE 1000000

/* 
	What is the fastest way to find matching numbers in two unsorted arrays?
	Method 1: we can iteratate through both arrays
	Method 2: we can sort one array and binary search in that array
	Method 3: we can hash one array and pass the other to the hash function
	Method 4: we can sort both arrays and then step through each one

	Control:
	- we need to use the same data set for each test. The data set can be randomly generated
	- each test needs to begin with the original data set (i.e. not sorted from a previous test)
	- most challenging control will be overcoming caching
	- a large enough array of numbers is needed for the most telling results
	- debug vs release will yield different results so both should be analysed
*/

void FillArray(unsigned int* array, unsigned int size)
{
	/* Random number generator */
	srand(time(0));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<unsigned long long> dis(0, 1000000000);
	
	for (size_t i = 0; i < size; i++)
		array[i] = dis(gen);
}

int main()
{
	/* Time keeping */
	clock_t time1, time2, time3, time4;
	double time_taken_1, time_taken_2, time_taken_3, time_taken_4;

	size_t size = SET_SIZE;
	int count1, count2, count3, count4;

	// Creating two arrays
	unsigned int* arr1 = new unsigned int[size];
	unsigned int* arr2 = new unsigned int[size];

	std::cout << std::endl;
	std::cout << "Creating Array 1" << std::endl;
	FillArray(arr1, size);
	
	std::cout << "Creating Array 2" << std::endl;
	FillArray(arr2, size);
	std::cout << std::endl;


	unsigned int* temp_arr1 = new unsigned int[size];
	unsigned int* temp_arr2 = new unsigned int[size];


	/* Method 1: Iterate through both arrays */
	std::memcpy(temp_arr1, arr1, size * sizeof(int));
	std::memcpy(temp_arr2, arr2, size * sizeof(int));

	std::cout << "Starting Iterative test." << std::endl;
	time1 = clock();
	count1 = testIterative(arr1, arr2, size);
	time1 = clock() - time1;
	time_taken_1 = ((double)time1) / CLOCKS_PER_SEC;
	std::cout << std::endl;

	std::cin.get();

	return 0;
}