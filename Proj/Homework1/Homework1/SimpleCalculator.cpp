#include "SimpleCalculator.h"
#include <iostream>

SimpleCalculator::SimpleCalculator()
{
	std::cout << "����� ������ �����: ";
	std::cin >> oneNumber;
	std::cout << "\n����� �������� '+' '-' '/' '*': ";
	std::cin >> operation;
	std::cout << "\n����� ������ �����: ";
	std::cin >> twoNumber;
	perfAction();
}

void SimpleCalculator::perfAction()
{
	std::cout << "�������� ��������� ��������: ";
	switch (operation)
	{
	case '+':
		std::cout << (oneNumber + twoNumber);
		break;
	case '-':
		std::cout << (oneNumber - twoNumber);
		break;
	case '/':
		std::cout << (oneNumber / twoNumber);
		break;
	case '*':
		std::cout << (oneNumber * twoNumber);
		break;
	default:
		break;
	}
}