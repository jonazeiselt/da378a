#include "../stdafx.h"
#include "../person/PersonMedTel.h"
#include "../person/Person.h"

#include <string>

std::string tel;

std::string PersonMedTel::getTel() const
{
	return tel;
}

void PersonMedTel::print() const
{
	std::cout << Person::getName() << ", Tfn: " << tel << "\n" << Person::getAddress() << std::endl;
}
