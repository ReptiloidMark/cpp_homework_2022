#include <iostream>
#include <string>


int main()
{
	setlocale(LC_ALL, "Russian");
	const int k = 1000;
	const long n = std::pow(10, 9);
	const long sgse = 3;
	std::cout << sgse;
	const int s = 100;

	int c = 0;

	std::string before;
	std::string after;
	std::string input;
	std::string output;

	std::cout << "Введите единицу измерения (Возможные варианты - kl, m, kg. Учтите, что перевод возможен только в передлах одной физической величины): ";
	std::cin >> before;
	std::cout << "\n";

	std::cout << "Введите значние: ";
	std::cin >> input;
	std::cout << "\n";
	
	std::cout << "Введите желаемую единицу измерения (Возможные варианты - kl, nkl, m, kg, SGSE, sm, g. Учтите, что перевод возможен только в передлах одной физической величины): ";
	std::cin >> after;
	std::cout << "\n";

	if (before == "kl") {
		if ((after == "kl") || (after == "nkl") || (after == "SGSE")) {
			if (after == "kl") {
				output = input;
			}
			if (after == "nkl") {
				output = input + std::to_string(n);
			}
			if (after == "SGSE") {
				long long_output = sgse * std::stol(input);
				output = std::to_string(long_output) + std::to_string(n);
			}
		}
		else {
			std::cout << "Неверная величина для перевода";
		}
		c += 1;
	}
	if (before == "m") {
		if (after == "sm" || after == "m") {
			if (after == "sm") {
				int int_output = s * std::stoi(input);
				output = std::to_string(int_output);
			}
			if (after == "m") {
				output = input;
			}
		}
		else {
			std::cout << "Неверная величина для перевода";
		}
		c += 1;
	}
	if (before == "kg") {
		if ((after == "kg") || (after == "g")) {
			if (after == "kg") {
				output = input;
			}
			if (after == "g") {
				int int_output = k * std::stoi(input);
				output = std::to_string(int_output);
			}
		}
		else {
			std::cout << "Неверная величина для перевода";
		}
		c += 1;
	}
	if (c == 0) {
		std::cout << "Неверный ввод величины";
	}
	else {
		std::cout << input << " " << before << " is " << output << " " << after << "\n";
	}
}
