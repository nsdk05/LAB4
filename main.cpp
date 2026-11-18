#include <iostream>
#include <stdexcept>
#include <string>

#include "Input.h"
#include "Point.h"

namespace {

void PrintTitle(const std::string& title) {
	std::cout << "\n" << title << "\n";
}

lab4::Point ReadPoint(const std::string& name) {
	std::cout << "Введите точку " << name << "\n";
	const double x = input::ReadDouble("x = ");
	const double y = input::ReadDouble("y = ");
	return lab4::Point(x, y);
}

void Task1() {
	PrintTitle("Задание 1: Конструкторы");
	const lab4::Point origin;
	std::cout << "Конструктор по умолчанию: " << origin << "\n";
	const lab4::Point point = ReadPoint("для конструктора (x, y)");
	std::cout << "Конструктор с параметрами: " << point << "\n";
	const lab4::Point copy(point);
	std::cout << "Конструктор копирования: " << copy << "\n";
}

void Task2() {
	PrintTitle("Задание 1: Расстояние между точками");
	const lab4::Point a = ReadPoint("A");
	const lab4::Point b = ReadPoint("B");
	std::cout << "A = " << a << ", B = " << b << "\n";
	std::cout << "Расстояние от A до B: " << a.DistanceTo(b) << "\n";
}

void Task3() {
	PrintTitle("Задание 2: Операции ++ и --");
	lab4::Point a = ReadPoint("A");
	std::cout << "A = " << a << "\n";
	++a;
	std::cout << "После ++A: " << a << "\n";
	--a;
	std::cout << "После --A: " << a << "\n";
	const lab4::Point before_inc = a++;
	std::cout << "A++ вернуло " << before_inc << ", теперь A = " << a << "\n";
	const lab4::Point before_dec = a--;
	std::cout << "A-- вернуло " << before_dec << ", теперь A = " << a << "\n";
}

void Task4() {
	PrintTitle("Задание 2: Приведение типов");
	const lab4::Point a = ReadPoint("A");
	std::cout << "A = " << a << "\n";
	const double y = a;
	std::cout << "double (неявное): координата y = " << y << "\n";
	try {
		const int whole_x = static_cast<int>(a);
		std::cout << "int (явное): целая часть x = " << whole_x << "\n";
	} catch (const std::out_of_range& error) {
		std::cout << "Ошибка: " << error.what() << "\n";
	}
}

void Task5() {
	PrintTitle("Задание 2: Операции +");
	const lab4::Point a = ReadPoint("A");
	const lab4::Point b = ReadPoint("B");
	const double distance = a + b;
	std::cout << "A + B (расстояние до B): " << distance << "\n";
	const int d = input::ReadInt("Введите целое число d = ");
	const lab4::Point shifted = a + d;
	std::cout << "A + d (сдвиг по x): " << shifted << "\n";
	std::cout << "Точка A не изменилась: " << a << "\n";
}

void PrintMenu() {
	std::cout << "\nВыберите задание\n";
	std::cout << "1: Задание 1 Конструкторы\n";
	std::cout << "2: Задание 1 Расстояние между точками\n";
	std::cout << "3: Задание 2 Операции ++ и --\n";
	std::cout << "4: Задание 2 Приведение типов\n";
	std::cout << "5: Задание 2 Операции +\n";
	std::cout << "0: Выход\n";
}

}  // namespace

int main() {
	while (true) {
		PrintMenu();
		const int choice = input::ReadIntInRange("Ваш выбор: ", 0, 5);
		switch (choice) {
			case 1: {
				Task1();
				break;
			}
			case 2: {
				Task2();
				break;
			}
			case 3: {
				Task3();
				break;
			}
			case 4: {
				Task4();
				break;
			}
			case 5: {
				Task5();
				break;
			}
			default: {
				return 0;
			}
		}
	}
}
