#include "stdafx.h"
#include "String.h"

String::String()
{
	String("");
}

String::String(const String & rhs)
{
	*this = rhs;
	Invariant();
}

String::String(const char * cstr)
{
	n = 0;
	cap = (sizeof(cstr) / sizeof(char));
	str = new char[cap];

	int i = 0;
	while (cstr[i] != '\0')
	{
		push_back(cstr[i]);
		i++;
	}
	Invariant();
}

String::~String()
{
	// Check if str is not a nullptr
	if (str)
	{
		Invariant();
		delete[] str;
	}
}

String & String::operator=(const String & rhs)
{
	if (&rhs != this)
	{
		if (str)
			delete[] str;

		n = rhs.size();
		cap = rhs.capacity();
		str = new char[cap];

		for (int i = 0; i < rhs.size(); i++)
			str[i] = rhs[i];
	}
	return *this;
}

char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i) const
{
	return str[i];
}

int String::size() const
{
	return n;
}

int String::capacity() const
{
	return cap;
}

void String::push_back(char c)
{
	if (size() == 0)
		allocateNewMemory(1);
	else if (size() >= capacity())
		allocateNewMemory(capacity() * 2);

	str[n++] = c;
}

bool operator==(const String & lhs, const String & rhs)
{
	return std::equal(lhs.str, lhs.str + lhs.size(), rhs.str);
}

std::ostream& operator<<(std::ostream & out, const String & rhs)
{
	for (int i = 0; i < rhs.size(); ++i)
		out << rhs[i];

	return out;
}

void String::Invariant() const
{
	assert(size() <= capacity());
}

void String::allocateNewMemory(int len)
{
	cap = len;

	// Allocate new memory
	char* tmp = new char[cap];

	// Copy over contents from str to tmp
	for (int i = 0; i < n; i++)
		tmp[i] = str[i];

	if (str)
		delete[] str;

	// Allocate new memory
	str = new char[cap];

	// Copy over contents from tmp to str
	for (int i = 0; i < n; i++)
		str[i] = tmp[i];

	delete[] tmp;
}
