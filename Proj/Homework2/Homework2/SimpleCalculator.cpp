#include "SimpleCalculator.h"

SimpleCalculator::SimpleCalculator(const std::string& path)
{
	logger = new Logger(path);
	oneNumber = enterUserData.enterDouble("����� ������ �����: ");
	logger->info("������������ ���� ������ �����: " + std::to_string(oneNumber));
	operation = enterUserData.enterChar("����� �������� '+' '-' '/' '*': ");
	logger->info("������������ ���� ��������: " + operation);
	twoNumber = enterUserData.enterDouble("����� ������ �����: ");
	logger->info("������������ ���� ������ �����: " + std::to_string(twoNumber));
	perfAction();
}

SimpleCalculator::~SimpleCalculator()
{
	logger = nullptr;
	//������������ ������� ��� ���������� �������������
}

void SimpleCalculator::perfAction()
{
	switch (operation)
	{
	case '+':
		logger->info("�������� ��������� ��������: "+ std::to_string(oneNumber + twoNumber));
		break;
	case '-':
		logger->info("�������� ��������� ��������: " + std::to_string(oneNumber - twoNumber));
		break;
	case '/':
		logger->info("�������� ��������� ��������: " + std::to_string(oneNumber / twoNumber));
		break;
	case '*':
		logger->info("�������� ��������� ��������: " + std::to_string(oneNumber * twoNumber));
		break;
	default:
		break;
	}
}
