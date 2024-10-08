#include "my_string.h"
#include <istream>
#include <ostream>

MyString::MyString(int size)
{
	setSize(size);
}

MyString::MyString(const char *c_str)
{
	copy(c_str);
}

MyString::MyString(const MyString &other)
{
	size = other.size;
	data = new char[size];
	for (int i = 0; i < size; ++i)
	{
		data[i] = other.data[i];
	}
}

void MyString::setSize(int size)
{
	if (size < 0)
		throw "Некорректный размер массива";
	if (this->size == size)
		return;
	char *tmp;
	if (this->size > 0)
	{
		tmp = new char[size];
		for (int i = 0; i < size; ++i)
		{
			tmp[i] = data[i];
		}
		delete[] data;
		data = nullptr;
	}
	if (size == 0)
		return;
	this->size = size;
	data = new char[size];
	for (int i = 0; i < size; ++i)
	{
		data[i] = tmp[i];
	}
}

std::ostream &operator<<(std::ostream &os, const MyString &str)
{
	if (str.size > 0)
		os << str.data;
	return os;
}

std::istream &operator>>(std::istream &is, MyString &str)
{
	char *tmp = new char[1000];
	is >> tmp;
	str.copy(tmp);
	delete[] tmp;
	return is;
}

void MyString::copy(const char *str)
{
	const char *p = str;
	int i_size = 0;
	while (*p != 0)
		++i_size;
	setSize(i_size + 1);
	for (int i = 0; i < size; ++i, ++str)
	{
		data[i] = *str;
	}
}

MyString::~MyString()
{
	setSize(0);
}