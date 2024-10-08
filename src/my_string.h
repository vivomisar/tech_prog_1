#ifndef MY_STRING_H
#define MY_STRING_H
#include <ostream>
class MyString
{
  private:
	int size;
	char *data;
	void resize();

  public:
	MyString();
	MyString(int size);
	MyString(const char *c_str);
	MyString(const MyString &str);
	friend std::ostream &operator<<(std::ostream &os, const MyString &str);
	friend std::istream &operator>>(std::istream &istream, MyString &str);
	MyString &operator=(MyString &other);
	void setSize(int size);
	void copy(const char *str);
	~MyString();
};
#endif