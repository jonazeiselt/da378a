#include "stdafx.h"
#include "PersonMedTel.h"
#include "Person.h"

#include <string>

std::string tel;

std::string PersonMedTel::getTel()
{
	return tel;
}

void PersonMedTel::print()
{
	std::cout << Person::getName() << ", Tfn: " << tel << "\n" << Person::getAddress() << std::endl;
}
