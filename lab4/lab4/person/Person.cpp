#include "../stdafx.h"
#include "../person/Person.h"

#include <iostream>
#include <string>

std::string name;
std::string address;

Person::Person(std::string name, std::string address)
{
	this->name = name;
	this->address = address;
}

Person::~Person() 
{
	// Empty
}

std::string Person::getName() const
{
	return name;
}
std::string Person::getAddress() const
{
	return address;
}

bool Person::operator<(const Person& that)
{
	return this->name < that.name;
}

void Person::print() const
{
	std::cout << name << " (" << address << ")";
}