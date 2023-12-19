#include "SimpleCalculator.h"

SimpleCalculator::SimpleCalculator(const std::string& path)
{
	logger = new Logger(path);
	oneNumber = enterUserData.enterDouble("Введи первое число: ");
	logger->info("Пользователь ввел первое число: " + std::to_string(oneNumber));
	operation = enterUserData.enterChar("Введи действие '+' '-' '/' '*': ");
	logger->info("Пользователь ввел операцию: " + operation);
	twoNumber = enterUserData.enterDouble("Введи второе число: ");
	logger->info("Пользователь ввел второе число: " + std::to_string(twoNumber));
	perfAction();
}

SimpleCalculator::~SimpleCalculator()
{
	logger = nullptr;
	//Освобождение ресурса при завершении использования
}

void SimpleCalculator::perfAction()
{
	switch (operation)
	{
	case '+':
		logger->info("Резуьтат выбранной операции: "+ std::to_string(oneNumber + twoNumber));
		break;
	case '-':
		logger->info("Резуьтат выбранной операции: " + std::to_string(oneNumber - twoNumber));
		break;
	case '/':
		logger->info("Резуьтат выбранной операции: " + std::to_string(oneNumber / twoNumber));
		break;
	case '*':
		logger->info("Резуьтат выбранной операции: " + std::to_string(oneNumber * twoNumber));
		break;
	default:
		break;
	}
}
