#ifndef PERSONREG_H
#define PERSONREG_H

#include "Person.h"
#include "PersonMedTel.h"

class PersonReg
{
private:
	Person* personer;
	int maxSize;
	int numPersoner;
public:
	PersonReg(int maxSize);
	void addPerson(Person* person);
	void removePerson(Person* person);
	Person* searchByName(std::string name);
	Person* searchByKeyword(std::string key, Person* keyword);
	Person* begin();
	Person* end();
	void printPersonReg();
	~PersonReg();
};

#endif // !PERSONREG_H