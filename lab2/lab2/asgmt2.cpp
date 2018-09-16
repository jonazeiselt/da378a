#include "stdafx.h"
#include "asgmt2.h"

void runAsgmt2(void)
{
	std::cout << "\nAssignment 2\nEnter a string: ";
	std::string ioString;

	/* Doesn't work without #include <string>
	   AND std::cin >> ioString reads only one word */
	getline(std::cin, ioString, '\n');

	substitute2(ioString, "ej", "ig");
	std::cout << "After: " << ioString << std::endl;

	std::cout << "\nEnter another string: ";

	// std::cin >> ioString;
	getline(std::cin, ioString, '\n');

	substitute2(ioString, "ej", "eje");
	std::cout << "After: " << ioString << std::endl;
}

void substitute2(std::string &ioString, const std::string &before, const std::string &after)
{
	int i = 0;
	while (i != -1 && i < ioString.size())
	{
		i = ioString.find(before, i);

		if (i != -1)
		{
			ioString.erase(i, before.size());
			ioString.insert(i, after);
			i += after.size();
		}
	}
}
