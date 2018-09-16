#ifndef PERSONMEDTEL_H
#define PERSONMEDTEL_H

#include "Person.h"
#include <iostream>

class PersonMedTel : public Person
{
private:
	std::string tel;
public:
	PersonMedTel() : Person(), tel("Okänt nummer") {}
	PersonMedTel(std::string name, std::string tel, std::string address) : Person(name, address), tel(tel) {}
	std::string getTel();
	void print();
};

#endif // !PERSONMEDTEL_H
