#include "keeper.h"
#include "hero.h"
#include "heroes.h"
#include "monster.h"
#include "villain.h"

Keeper::Keeper() : size(0), capacity(0), data(nullptr)
{
	std::cout << "Конструктор: Keeper (без параметров)\n";
}

Keeper::Keeper(Keeper &other)
{
	std::cout << "Конструктор: Keeper (копирования)\n";
}

Keeper::Keeper(const std::string &path)
{
	std::cout << "Конструктор: Keeper (с параметрами)\n";
}
Heroes &Keeper::operator[](int index)
{
	if (index < 0 || index >= size)
		throw "Некорректный индекс";
	return *data[index];
}

void Keeper::setSize(int size)
{
	if (size < 0)
		throw "Некорректный размер массива";
	if (this->size == size)
		return;
	Heroes **tmp;
	if (this->size > 0)
	{
		tmp = new Heroes *[this->size];
		for (int i = 0; i < this->size; ++i)
		{
			tmp[i] = data[i];
		}
		if (size == 0)
		{
			for (int i = 0; i < this->size; ++i)
			{
				delete data[i];
			}
		}

		delete[] data;
		data = nullptr;
	}
	if (size == 0)
		return;
	data = new Heroes *[size];
	for (int i = 0; i < this->size; ++i)
	{
		data[i] = tmp[i];
	}
	this->size = this->capacity = size;
}

void Keeper::add(Heroes *entity)
{
	if (capacity == size)
		setSize(size + 1);
	data[size - 1] = entity;
}

void Keeper::normalize(int index)
{
	for (int i = index; i < size - 1; ++i)
	{
		data[i] = data[i + 1];
	}
	data[--size] = nullptr;
}

void Keeper::remove(int index)
{
	if (index < 0 || index > size)
		throw "Некорректный индекс";
	delete data[index];
	normalize(index);
}
void Keeper::recover(std::istream &is)
{
	int t_size;
	is >> t_size;
	setSize(t_size);
	for (int i = 0; i < size; ++i)
	{
		std::string type;
		is >> type;
		if (type == "Hero:")
		{
			data[i] = new Hero();
		}
		else if (type == "Villain:")
		{
			data[i] = new Villain();
		}
		else if (type == "Monster:")
		{
			data[i] = new Monster();
		}
		else
		{
			throw "Неизвестный тип";
		}
		data[i]->load(is);
	}
}
void Keeper::save(std::ostream &os)
{
	os << size << "\n";
	for (int i = 0; i < size; ++i)
	{
		os << data[i]->type() << ": \n\t";
		data[i]->save(os);
	}
}
Keeper::~Keeper()
{
	setSize(0);
	std::cout << "Деструктор: Keeper\n";
}