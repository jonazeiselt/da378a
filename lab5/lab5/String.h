#ifndef STRING_H
#define STRING_H

#include <cassert>
#include <iostream>
#include <algorithm>
#include <iterator>

class String
{
private:
	char *str = nullptr;  // new char[1];
	int n = 0;
	int cap = 1;
	
	void Invariant() const;
	void allocateNewMemory(int len);
public:
	String();
	String(const String& rhs);
	String(const char* cstr);
	~String();

	String& operator=(const String& rhs);
	char& operator[](int i);
	const char& operator[](int i) const;

	int size() const;
	int capacity() const;
	void push_back(char c);

	friend bool operator==(const String& lhs, const String& rhs);
	friend std::ostream& operator<<(std::ostream& out, const String& rhs);
};

#endif // !STRING_H

