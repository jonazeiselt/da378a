#include "stdafx.h"
#include "asgmt1.h"

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

void runAsgmt1()
{
	int N = 20;

	// 1a
	std::cout << "1a ~ vector<int>, asc." << std::endl;
	sortAscOrderVector(N);

	// 1b
	std::cout << "\n1b ~ int[], asc." << std::endl;
	sortAscOrderCArray(N);

	// 1c
	std::cout << "\n1c ~ vector<int>, desc." << std::endl;
	sortDescOrderVector(N);

	// 1d
	std::cout << "\n1d ~ int[], desc." << std::endl;
	sortDescOrderCArray(N);
}

void sortAscOrderVector(const int& N)
{
	// Create std::vector<int>, random order
	std::vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int r = std::rand() % N; // [0,N)
		v.push_back(r);
	}
	std::random_shuffle(v.begin(), v.end());

	// Print container
	printVector(v);

	// Sort with std::sort
	std::sort(v.begin(), v.end());

	// Print container
	printVector(v);
}

void sortAscOrderCArray(const int& N)
{
	// Create int[], random order
	int c[20];
	for (int i = 0; i < N; i++)
	{
		int r = std::rand() % N; // [0,N)
		c[i] = r;
	}
	std::random_shuffle(c, c+N);

	// Print container
	printCArray(c, sizeof(c)/sizeof(int));

	// Sort with std::sort
	std::sort(c, c+N);

	// Print container
	printCArray(c, sizeof(c) / sizeof(int));
}

void sortDescOrderVector(const int& N)
{
	// Create std::vector<int>, random order
	std::vector<int> v(N);
	std::iota(v.begin(), v.end(), N); // [N,2N)
	std::random_shuffle(v.begin(), v.end());

	// Print container
	printVector(v);

	// Sort with std::sort
	std::sort(v.rbegin(), v.rend());

	// Print container
	printVector(v);
}

void sortDescOrderCArray(const int& N)
{
	// Create int[], random order
	int c[20];
	std::iota(c, c + N, N); // [N,2N)
	std::random_shuffle(std::begin(c), std::end(c)); // OR ..(c, C+N)

	// Print container
	printCArray(c, sizeof(c) / sizeof(int));

	// Sort with std::sort
	std::sort(c, c + N, greater);
	
	// Print container
	printCArray(c, sizeof(c) / sizeof(int));
}

void printVector(const std::vector<int>& v)
{
	for (int i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}

void printCArray(int c[], int length)
{
	for (int i = 0; i < length; i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;
}

bool greater(int x, int y)
{
	return x > y;
}
