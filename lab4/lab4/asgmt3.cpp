#include "stdafx.h"
#include "asgmt3.h"
#include "asgmt1.h"

#include <iostream>
#include <algorithm>
#include <vector>

void runAsgmt3()
{
	std::cout << "\n3 ~ vector<int>" << std::endl;

	int N = 20;

	// Create container, random order
	std::vector<int> v;
	for (int i = 0; i < N; i++)
	{
		v.push_back(i);
	}
	std::random_shuffle(v.begin(), v.end());

	// Print container
	printVector(v);

	// Remove even numbers (remove_if and erase)
	v.erase(std::remove_if(v.begin(), v.end(), even), v.end());

	// Print container
	printVector(v);
}

bool even(int i)
{
	return (i % 2) == 0;
}
