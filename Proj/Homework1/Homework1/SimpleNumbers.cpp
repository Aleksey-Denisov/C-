#include "SimpleNumbers.h"
#include <iostream>

SimpleNumbers::SimpleNumbers()
{
	bool flag = true;
	int sum = 0;
	for (int idElement = 2; idElement <= 1000; idElement++)
	{
		for (int delimetr = 2; delimetr < idElement; delimetr++)
		{
			if (idElement % delimetr == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			std::cout << idElement << " ";
			sum++;
			if (sum % 30 == 0)
			{
				std::cout << std::endl;
			}
		}
		else
		{
			flag = true;
		}
	}
}
