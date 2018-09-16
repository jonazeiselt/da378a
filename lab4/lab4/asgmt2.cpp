#include "stdafx.h"

#include "asgmt2.h"
#include "person/PersonReg.h"

#include <iostream>
#include <algorithm>

void runAsgmt2()
{
	// 2a
	std::cout << "\n2a ~ asc." << std::endl;
	sortAscOrder();
	
	// 2b
	std::cout << "\n2b ~ desc." << std::endl;
	sortDescOrder();
}

void sortAscOrder()
{
	// Create PersonReg
	PersonReg *reg = new PersonReg(10);
	reg->addPerson(&Person("A", "A Street"));
	reg->addPerson(&Person("A", "B Street"));
	reg->addPerson(&Person("A", "C Street"));
	reg->addPerson(&Person("Ab", "D Street"));
	reg->addPerson(&Person("Ab", "E Street"));
	reg->addPerson(&Person("Ab", "F Street"));
	reg->addPerson(&Person("B", "G Street"));

	// Random shuffle
	std::random_shuffle(reg->begin(), reg->end());

	// Print container
	reg->printPersonReg();

	// Sort with std::sort
	std::sort(reg->begin(), reg->end());

	// Print container
	reg->printPersonReg();

	delete reg;
}

void sortDescOrder()
{
	// Create PersonReg
	PersonReg *reg = new PersonReg(10);
	reg->addPerson(&Person("A", "A Street"));
	reg->addPerson(&Person("A", "B Street"));
	reg->addPerson(&Person("A", "C Street"));
	reg->addPerson(&Person("Ab", "D Street"));
	reg->addPerson(&Person("Ab", "E Street"));
	reg->addPerson(&Person("Ab", "F Street"));
	reg->addPerson(&Person("A", "G Street"));

	// Random shuffle
	std::random_shuffle(reg->begin(), reg->end());

	// Print container
	reg->printPersonReg();

	// Sort with std::sort
	std::sort(reg->begin(), reg->end(), greater);

	// Print container
	reg->printPersonReg();

	delete reg;
}

bool greater(Person x, Person y)
{ 
	return x.getAddress() > y.getAddress(); 
}