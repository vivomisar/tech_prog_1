#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
class MyString
{
  private:
	int size;
	int text_size;
	char *data;
	void append(const char *str);

  public:
	MyString();
	MyString(int size);
	MyString(const char *c_str);
	MyString(const MyString &str);
	friend std::ostream &operator<<(std::ostream &os, const MyString &str);
	friend std::istream &operator>>(std::istream &istream, MyString &str);
	MyString &operator=(MyString &other);
	MyString operator+(MyString &other);
	MyString operator+(const char *str);
	void setSize(int size);
	int getSize();
	void copy(const char *str);
	~MyString();
};
#endif