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
	Person* searchByName(const std::string& name) const;
	Person* searchByKeyword(const std::string& key, Person* keyword) const;
	Person* begin() const;
	Person* end() const;
	void printPersonReg() const;
	~PersonReg();
};

#endif // !PERSONREG_H