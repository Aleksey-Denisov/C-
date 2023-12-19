#include "EnteringUserData.h"
#include <iostream>
int EnteringUserData::enterInt(std::string message)
{
	int userData = 0;
	while (true)
	{
		std::cout << message;
		std::string line;
		std::getline(std::cin, line);
		bool flag = true;
		try 
		{
			userData = std::stoi(line);
			break;
		}
		catch (std::invalid_argument const& arg)
		{
			std::cout << "�� ����� �������� �����, ���������� ��� ���!" << std::endl;
		}
		catch (std::out_of_range const& arg)
		{
			std::cout << "�� ����� �� ���������� �������� ��������, ���������� ��� ���!" << std::endl;
		}
	}
	return userData;
}

double EnteringUserData::enterDouble(std::string message)
{
	double userData = 0;
	while (true)
	{
		std::cout << message;
		std::string line;
		std::getline(std::cin, line);
		bool flag = true;
		try 
		{
			userData = std::stod(line);
			break;
		}
		catch (std::invalid_argument const& arg)
		{
			std::cout << "�� ����� �������� �����, ���������� ��� ���!" << std::endl;
		}
		catch (std::out_of_range const& arg)
		{
			std::cout << "�� ����� �� ���������� �������� ��������, ���������� ��� ���!" << std::endl;
		}
	}
	return userData;
}

char EnteringUserData::enterChar(std::string message)
{
	char userData;
	while (true)
	{
		std::cout << message;
		std::cin >> userData;
		if (userData == '+' || userData == '-' || userData == '/' || userData == '*')
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			break;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "�� ����� �������� ������, ���������� ��� ���!" << std::endl;
		}
	}
	return userData;
}
