#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
private:
	std::string name;
	std::string address;
public:
	Person() : name("Ok�nt namn"), address("Ok�nd adress") {}
	Person(std::string name, std::string address);
	virtual ~Person();
	std::string getName();
	std::string getAddress();
	bool operator< (const Person& that);
	virtual void print();
};

#endif // !PERSON_H
