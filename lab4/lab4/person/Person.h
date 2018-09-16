#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
private:
	std::string name;
	std::string address;
public:
	Person() : name("Okänt namn"), address("Okänd adress") {}
	Person(std::string name, std::string address);
	virtual ~Person();
	std::string getName() const;
	std::string getAddress() const;
	bool operator<(const Person& that);
	virtual void print() const;
};

#endif // !PERSON_H
