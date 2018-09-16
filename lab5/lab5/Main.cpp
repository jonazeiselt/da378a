#include "stdafx.h"

#include <stdlib.h>
#include <crtdbg.h>

//#define VG

#include "String.h"

#include <string>
#include <iostream>
#include <cassert>
#include <utility>

// using namespace std;

void TestFörGodkäntString();
void TestFörVälGodkäntString();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::locale::global(std::locale("swedish"));
	
	TestFörGodkäntString();
	TestFörVälGodkäntString();
	// std::cin.get();
}

void TestPushBackReallocation() 
{
	String str("hej");
	assert(str.size() <= str.capacity());

#ifdef VG
	//If VG we try to take 20 empty places: (size+1 < capacity)
	while (str.size() + 20 >= str.capacity() && str.size() < 1000)
		str.push_back('A' + rand() % 32);
	assert(str.size() < 1000);	//If this fail it prbably the case that capacity is increased with a constant.
#endif //VG

	auto internalBuf = &str[0];
	auto cap = str.capacity();
	auto siz = str.size();
	int i;
	for (i = siz + 1; i <= cap; ++i) {
		str.push_back(char(i) + 'a');
		assert(internalBuf == &str[0]);
		assert(cap == str.capacity());
		assert(i == str.size());
	}
	str.push_back(char(i));
	assert(internalBuf != &str[0]);
	assert(cap < str.capacity());
	assert(i == str.size());
}

void TestFörGodkäntString() 
{
	//-	String()
	String str0;	assert(str0 == "");

	//-	String(Sträng sträng)
	String s1("foo"); assert(s1 == "foo");
	String str(s1); assert(str == "foo");
	String s3("bar");  assert(s3 == "bar");

	//-	~String() Kom ihåg destruktorn!
	delete new String("hej");

	//	-	operator =(Sträng sträng)
	assert((str = s3) == s3);
	assert((str = str) == s3);	//self assignment

	String str1("foo"), str2("bar"), str3("hej");
	str3 = str = str1;
	assert(str3 == str);
	assert(str1 == str);

	//-	operator== 
	//testas överallt!

	//-	operator[](int i) som indexerar utan range check.
	str = "bar";
	str[-1]; str[1000];	//No error
	assert(str[1] == 'a');
	str[1] = 'y';
	assert(str[1] == 'y');

	const String sc(str);
	assert(sc[1] == 'y');
	assert(std::is_const<std::remove_reference< decltype(sc[1])>::type>::value); //Kolla att det blir en const resultat av indexering

																				 //-	push_back(char c) lägger till ett tecken sist.
	str = "bar";
	str.push_back('a');
	assert(str == "bara");

	//-	size(), capacity() and reloccation test;
	TestPushBackReallocation();

	std::cout << String("hej\n");
	std::cout << "Om det står hej på föregående rad så är TestFörGodkänt klar\n";
}

void TestFörVälGodkäntString() 
{
#ifdef VG
	String str("bar");

	//-	at(int i) som indexerar med range check
	try {
		str.at(-1);
		assert(false);
	}
	catch (std::out_of_range&) {};
	try {
		str.at(3);
		assert(false);
	}
	catch (std::out_of_range&) {};

	//- at indexerar

	//-	at(int i) 
	str = "bar";
	assert(str.at(1) == 'a');
	str.at(1) = 'y';
	assert(str.at(1) == 'y');

	const String strC(str);
	assert(strC.at(1) == 'y');
	assert(std::is_const<std::remove_reference< decltype(strC.at(1))>::type>::value); //Kolla att det blir en const resultat av indexering

																					  // ConvertToChars
	char* temp = strC.ConvertToChars();
	assert(strC.size() == 3);
	assert(std::memcmp(temp, &strC[0], strC.size()) == 0);
	assert(temp[strC.size()] == '\0');
	delete temp;

	//	reserve()
	auto internalBuf = &str[0];
	auto cap = str.capacity();
	auto siz = str.size();

	str.reserve(cap);
	assert(internalBuf == &str[0]);
	assert(cap == str.capacity());
	assert(siz == str.size());

	str.reserve(cap + 1);
	assert(internalBuf != &str[0]);
	assert(cap + 1 == str.capacity());
	assert(siz == str.size());

	/////////////////
	//-	operator+=(Sträng sträng) som tolkas som konkatenering.
	//foo, bar, hej
	String str1("foo"), str2("bar"), str3("hej");
	((str = "xyz") += str1) += (str3 += str1);
	assert(str3 == "hejfoo" && str == "xyzfoohejfoo" && str1 == "foo");

	//+= som får plats;
	str = "bar"; str.reserve(10);
	str += "foo";
	assert(str == "barfoo");

	//+= som inte får plats;
	str.reserve(10);
	str = "";
	int i;
	for (i = 0; str.size() < str.capacity(); ++i)
		str.push_back('0' + i);
	str1 = "bar";
	str += str1;
	for (int k = 0; k < i; ++k)
		assert(str[k] == '0' + k);
	assert(str[i] == 'b');
	//+= Själv assignment	//Borde testa med att capacity tar slut!
	str = "foo";
	str += str;
	assert(str == "foofoo");

	//-	operator+
	str = "bar";
	assert(str + "foo" == "barfoo");

	cout << "\nTestFörVälGodkänt klar\n";
#endif //VG
}

