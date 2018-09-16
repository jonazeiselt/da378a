#include "stdafx.h"
#include "Person.h"

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

std::string Person::getName()
{
	return name;
}
std::string Person::getAddress()
{
	return address;
}

bool Person::operator<(const Person & that)
{
	return this->name < that.name;
}

void Person::print()
{
	std::cout << name << "\n" << address << std::endl;
}