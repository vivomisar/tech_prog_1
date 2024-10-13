/* Класс Герои хранит данные о положительных героях, злодеях и монстрах. Для
каждого героя определено: имя, тип оружия, основные навыки (несколько).
Для каждого злодея определено: имя, тип оружия, какое злодеяние совершил,
где обитает, основные навыки. Для каждого монстра: наименование, описание
внешнего вида */

#include "keeper.h"
#include "villain.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
	std::ifstream input;
	std::ofstream output;
	std::string path, name, weapon, skills, desc, atrocity, location;
	Keeper keeper;
	Heroes *tmp;
	char choice;
	int index;

	while (true)
	{
		choice = 0;
		std::cout << "1 – Загрузить из файла;\n"
		          << "2 – Сохранить в файл;\n"
		          << "3 – Вывести все элементы;\n"
		          << "4 – Вывести элемент;\n"
		          << "5 – Добавить элемент;\n"
		          << "6 – Удалить элемент;\n"
		          << "7 – Изменить элемент;\n"
		          << "0 – Выход из программы.\n>> ";
		std::cin >> choice;
		if (choice == '0')
		{
			break;
		}
		switch (choice)
		{
		case '1': /* Загрузить из файла */
			std::cout << "Введите путь до файла >> ";
			std::cin >> path;
			try
			{
				input.open(path);
				if (!input.is_open())
				{
					throw "Невозможно открыть файл";
				}
				keeper.recover(input);
			}
			catch (const char *err)
			{
				std::cerr << err;
			}
			input.close();
			break;
		case '2': /* Сохранить в файл */
			std::cout << "Введите путь до файла >> ";
			std::cin >> path;
			try
			{
				output.open(path);
				if (!output.is_open())
				{
					throw "Невозможно открыть файл";
				}
				keeper.save(output);
			}
			catch (const char *err)
			{
				std::cerr << err << "\n";
			}
			input.close();
			break;
		case '3': /* Вывести все элементы*/
			keeper.save(std::cout);
			break;
		case '4': /* Вывести элемент */
			std::cout << "Введите индекс элемента >> ";
			std::cin >> index;
			try
			{
				std::cout << keeper[index];
			}
			catch (const char *err)
			{
				std::cerr << err << "\n";
			}
			break;
		case '5': /* Добавить элемент */
			std::cout << "1 – Герой;\n"
			          << "2 – Злодей;\n"
			          << "3 – Монстр;\n>> ";
			std::cin >> choice;
			switch (choice)
			{
			case '1':
				std::cout << "Введите имя >> ";
				std::cin.ignore();
				getline(std::cin, name);
				std::cout << "Введите тип оружия >> ";
				getline(std::cin, weapon);
				std::cout << "Введите навыки >> ";
				getline(std::cin, skills);
				tmp = new Hero(name, weapon, skills);
				keeper.add(tmp);
				break;
			case '2':
				std::cout << "Введите имя >> ";
				std::cin.ignore();
				getline(std::cin, name);
				std::cout << "Введите тип оружия >> ";
				getline(std::cin, weapon);
				std::cout << "Введите навыки >> ";
				getline(std::cin, skills);
				std::cout << "Введите локацию >> ";
				getline(std::cin, location);
				std::cout << "Введите злодеяние >> ";
				getline(std::cin, atrocity);
				tmp = new Villain(name, weapon, atrocity, location, skills);
				keeper.add(tmp);
				break;
			case '3':
				std::cout << "Введите наименование >> ";
				std::cin.ignore();
				getline(std::cin, name);
				std::cout << "Введите описание >> ";
				getline(std::cin, desc);
				tmp = new Monster(name, desc);
				keeper.add(tmp);
				break;
			default:
				std::cerr << "Неверный выбор\n";
				break;
			}
			break;
		case '6': /* Удалить элемент */
			std::cout << "Введите индекс элемента >> ";
			std::cin >> index;
			try
			{
				keeper.remove(index);
			}
			catch (const char *err)
			{
				std::cerr << err << "\n";
			}
			break;
		case '7': /* Изменить элемент */
			std::cout << "Введите индекс элемента >> ";
			std::cin >> index;
			keeper[index].edit();
			break;

		default:
			std::cerr << "Неверный параметр\n";
			break;
		}
	}

	return 0;
}