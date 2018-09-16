#include "stdafx.h"
#include "PersonReg.h"

#include <string>
#include <fstream>

bool readReg(PersonReg& reg, std::string fileName);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::locale::global(std::locale("swedish"));

	PersonReg* reg = new PersonReg(15);

	// Add Person to reg
	Person* me = new Person("Jonas Eiselt", "Diamantvägen 14R, 262 70 ÄNGELHOLM");
	reg->addPerson(me);

	// Add Person objects to reg
	std::string fileName = "C:/Users/Acer/Documents/Malmö Högskola/DA378A/lab3/lab3/lab3/PersonExempel.txt";
	readReg(*reg, fileName);

	// Print PersonReg
	std::cout << "\nPrint PersonReg\n~~~~~~" << std::endl;
	reg->printPersonReg();

	// Remove Person from reg
	reg->removePerson(&Person("Gustav Sandberg", "Hagag 77, 443 65  STENKULLEN"));
	std::cout << "\nPrint PersonReg" << "\n~~~~~~" << std::endl;
	reg->printPersonReg();

	// Search by name
	std::string lookUp = "Jonas Eiselt";
	std::cout << "\nSearch by name: \"" << lookUp << "\"\n~~~~~~" << std::endl;
	Person* searchResult = reg->searchByName(lookUp);
	searchResult->print();

	// Search by keyword/term
	lookUp = "ALA";
	std::cout << "\nSearch by keyword: \"" << lookUp << "\"\n~~~~~~" << std::endl;
	Person* x1 = reg->searchByKeyword(lookUp, nullptr);

	// Make sure x1 isn't a nullptr
	if (x1)
		x1->print();

	// Search by keyword/term
	lookUp = "VRE";
	std::cout << "\nSearch by keyword: \"" << lookUp << "\"\n~~~~~~" << std::endl;
	Person* x2 = reg->searchByKeyword(lookUp, x1);

	// Make sure x2 isn't a nullptr
	if (x2)
		x2->print();

	// Print Person with tel
	std::cout << "\nPrint PersonMedTel\n~~~~~~" << std::endl;
	Person* myPerson = new PersonMedTel("Sven Svensson", "0705-432101", "Stjärngränd 35, 555 55 ÅKARP");
	myPerson->print();

	// Add PersonMedTel to reg
	reg->addPerson(myPerson);

	// Print reg
	std::cout << "\nPrint PersonReg\n~~~~~~" << std::endl;
	reg->printPersonReg();

	delete myPerson;
	delete me;
	delete reg;

	// Prevent console application from exiting
	std::getchar();

	return 0;
}

bool readReg(PersonReg& reg, std::string fileName)
{
	std::string line;
	std::ifstream myfile(fileName);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			while (line.length() == 0 && getline(myfile, line));

			std::string name(line);
			std::string adress;
			getline(myfile, adress);
			reg.addPerson(&Person(name, adress));
		}
		myfile.close();
		return true;
	}
	else
	{
		std::cout << "Unable to open file";
		return false;
	}
}