#include "stdafx.h"
#include "asgmt1.h"

#include <iostream>

void runAsgmt1()
{
	std::cout << "\nAssignment 1\nEnter a number: ";

	int N; 
	std::cin >> N;

	// If N = 5 -> 2,3,4,5 -> 4 ints
	int size = N - 1;

	// 1
	int *primes = new int[size];
	for (int i = 0; i < size; i++)
		primes[i] = i+2;
	
	std::cout << "Before: ";
	printArray(primes, size);

	// 2
	int num = 2;
	for (int i = 0; i < size; i++)
	{
		if (primes[i] > num && primes[i] % num == 0)
			primes[i] = 0;
	}

	// 5
	while (num*num < max(primes, size))
	{	
		num = getNextNum(primes, num, size);
		std::cout << "next num=" << num << std::endl;

		// 3 and 4
		for (int i = 0; i < size; i++)
			if (primes[i] > num && primes[i] % num == 0)
				primes[i] = 0;
	}

	// 6
	std::cout << "After: ";
	printArray(primes, size);
}

/* Print an int array with a given size */
void printArray(int *array, int size)
{
	for (int i = 0; i < size; i++)
		if (array[i])
			std::cout << array[i] << " ";
	std::cout << std::endl;
}

/* Return next number in array which is not deleted */
int getNextNum(int *array, int prevNum, int size)
{
	int i = 0;
	while ((array[i] <= prevNum || array[i] == 0) && i < size)
		i++;

	return array[i];
}

/* Return biggest number of array which is not deleted */
int max(int *array, int size)
{
	int i = size - 1;
	while (array[i] == 0 && i >= 0)
		i--;

	return array[i];
}