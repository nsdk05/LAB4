#include "Input.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

namespace input {

std::string ReadLine(const std::string& message) {
	std::cout << message;
	std::string line = "";
	if (!std::getline(std::cin, line)) {
		std::cout << "Ввод завершён \n";
		std::exit(0);
	}
	return line;
}

int ReadInt(const std::string& message) {
	while (true) {
		std::istringstream stream(ReadLine(message));
		int value = 0;
		char extra = '\0';
		if (stream >> value && !(stream >> extra)) {
			return value;
		}
		std::cout << "Ошибка: нужно ввести целое число \n";
	}
}

double ReadDouble(const std::string& message) {
	while (true) {
		std::istringstream stream(ReadLine(message));
		double value = 0.0;
		char extra = '\0';
		if (stream >> value && !(stream >> extra)) {
			return value;
		}
		std::cout << "Ошибка: нужно ввести число \n";
	}
}

char ReadCharToNum(const std::string& message) {
	while (true) {
		std::string line = ReadLine(message);
		if (line.size() == 1 && line[0] >= '0' && line[0] <= '9') {
			return line[0];
		}
		std::cout << "Ошибка: нужно ввести один символ от 0 до 9 \n";
	}
}

int ReadIntInRange(const std::string& message, int min_value, int max_value) {
	while (true) {
		int value = ReadInt(message);
		if (value >= min_value && value <= max_value) {
			return value;
		}
		std::cout << "Ошибка: число должно быть от " << min_value
				<< " до " << max_value << " \n";
	}
}

void ReadArr(int* arr, int size, const std::string& name) {
	for (int i = 0; i < size; ++i) {
		arr[i] = ReadInt(name + "[" + std::to_string(i) + "] = ");
	}
}

}  // namespace input
