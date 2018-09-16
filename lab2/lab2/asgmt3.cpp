#include "stdafx.h"
#include "asgmt3.h"

void runAsgmt3()
{
	std::string ioString;
	std::cout << "\nAssignment 3\nEnter a string: ";
	
	getline(std::cin, ioString);
	int len = ioString.size();
	
	char* const input = new char[len+1]; // +1 for \0
	std::strncpy(input, ioString.c_str(), len);
	input[len] = '\0';

	substitute3(input, 'j', "ig");
	std::cout << "After: " << std::string(input) << std::endl;
}

char* substitute3(char* const input, const char before, char* const after)
{
	std::cout << "Before: " << std::string(input) << std::endl;
	std::cout << "Length before: " << strlen(input) << std::endl;

	// Count number of instances of variable before in input
	int cnt = 0;
	for (int i = 0; input[i] != '\0'; i++)
		if (input[i] == before)
			cnt++;

	// Calculate new length of c string
	int len = strlen(input) + (cnt*strlen(after)) - cnt;
	char* const tmp = new char[len];

	std::cout << "Length after: " << len << std::endl;

	// Replace all instances of variable before with variable after
	for (int i = 0, t = 0; i < len; i++)
	{
		std::cout << "t=" << t << " ";
		if (before == input[i])
		{
			// Traverse variable after
			for (int a = 0; a < strlen(after); a++)
				tmp[t++] = after[a];
		}
		else
			tmp[t++] = input[i];
	}
	std::cout << std::endl;

	// Copy over contents from tmp to input
	for (int i = 0; i < len; i++)
		input[i] = tmp[i];
	input[len] = '\0';

	// delete[] tmp;

	return input;
}
