#include "SumAndMulty.h"
#include <iostream>

void SumAndMulty::sumNumbers()
{
	int sumNumbers = 0;
	for (int idElement = 0; idElement <= number; idElement++)
	{
		sumNumbers += idElement;
	}
	std::cout << "Сумма всех элементов равна: " << sumNumbers << std::endl;
}

void SumAndMulty::factorialNumber()
{
	int multiply = 1;
	for (int idElement = 2; idElement <= number; idElement++)
	{
		multiply *= idElement;
	}
	std::cout << "Факториал числа " << number << " равен: " << multiply << std::endl;
}

SumAndMulty::SumAndMulty()
{
	std::cout << "Введи число: ";
	std::cin >> this->number;
	sumNumbers();
	factorialNumber();
}