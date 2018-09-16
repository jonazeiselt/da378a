#include "../stdafx.h"
#include "../person/PersonReg.h"

#include <algorithm>

int maxSize;
int numPersoner;
Person* personer;

/* Constructor */
PersonReg::PersonReg(int maxSize)
{
	this->maxSize = maxSize;
	this->numPersoner = 0;

	// Allocate memory on heap
	personer = new Person[maxSize];
}

/* Destructor */
PersonReg::~PersonReg()
{
	// Release heap allocation
	delete[] personer;
}

/* Function */
void PersonReg::addPerson(Person* person)
{
	personer[numPersoner] = *person;
	numPersoner++;
}

/* Function */
void PersonReg::removePerson(Person* person)
{
	Person* deletePerson = nullptr;
	int i = 0;
	for (Person* ptr = personer; ptr != personer + numPersoner; ++ptr)
	{
		if ((ptr->getName()).compare(person->getName()) == 0 && (ptr->getAddress()).compare(person->getAddress()) == 0)
		{
			deletePerson = ptr;
			break;
		}
		i++;
	}

	if (deletePerson)
	{
		for (int k = i; k < numPersoner; k++)
		{
			personer[k] = personer[k + 1];                      
		}
		numPersoner--;
	}
	else
		std::cout << "Error: Person to be deleted doesn't exist" << std::endl;
}

Person * PersonReg::searchByName(const std::string& name) const
{
	for (Person* ptr = personer; ptr != personer + numPersoner; ++ptr)
	{
		if ((ptr->getName()).compare(name) == 0)
			return ptr;
	}
	return nullptr;
}

Person * PersonReg::searchByKeyword(const std::string& key, Person* fromPerson) const
{
	if (fromPerson == nullptr)
		fromPerson = personer;
	else
		fromPerson = (fromPerson + 1);
	
	for (Person* ptr = fromPerson; (ptr->getName()).compare(std::string("Okänt namn")) != 0; ++ptr)
	{
		if ((ptr->getName()).find(key, 0) != -1 || (ptr->getAddress()).find(key, 0) != -1)
			return ptr;
	}
	return nullptr;
}

Person * PersonReg::begin() const
{
	return personer;
}

Person * PersonReg::end() const
{
	return personer + numPersoner;
}

void PersonReg::printPersonReg() const
{
	for (Person* ptr = personer; ptr != personer + numPersoner; ++ptr)
	{
		ptr->print();
		std::cout << " ";
	}
	std::cout << std::endl;
}