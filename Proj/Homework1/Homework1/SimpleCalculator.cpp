#include "SimpleCalculator.h"
#include <iostream>

SimpleCalculator::SimpleCalculator()
{
	std::cout << "¬веди первое число: ";
	std::cin >> oneNumber;
	std::cout << "\n¬веди действие '+' '-' '/' '*': ";
	std::cin >> operation;
	std::cout << "\n¬веди второе число: ";
	std::cin >> twoNumber;
	perfAction();
}

void SimpleCalculator::perfAction()
{
	std::cout << "–езуьтат выбранной операции: ";
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