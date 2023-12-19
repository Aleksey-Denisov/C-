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
			std::cout << "Вы ввели неверное число, попробуйте ещё раз!" << std::endl;
		}
		catch (std::out_of_range const& arg)
		{
			std::cout << "Вы вышли за допустимый диапазон значений, попробуйте ещё раз!" << std::endl;
		}
	}
	return userData;
}
