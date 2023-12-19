#include "ArrayBubble.h"
#include <iostream>

ArrayBubble::ArrayBubble(const std::string& path)
{
	logger = new Logger(path);
	sizeArray = enterUserData.enterInt("¬веди число размера массива: ");
	inArray = new int[sizeArray];
	for (int idElementArray = 0; idElementArray < sizeArray; idElementArray++)
	{
		inArray[idElementArray] = enterUserData.enterInt("¬ведите " + std::to_string(idElementArray) + " элемент массива: ");
		forLog += std::to_string(inArray[idElementArray]) + " ";
	}
	logger->info("ѕользователь ввел следующий массив данных дл€ сортировки: " + forLog);
}

ArrayBubble::~ArrayBubble()
{
	delete[] inArray;
	inArray = nullptr;
	logger = nullptr;
}

void ArrayBubble::printer()
{
	forLog = "";
	for (int idElement = 0; idElement < sizeArray; idElement++)
	{
		forLog += std::to_string(inArray[idElement]) + " ";
	}
	std::cout << forLog << std::endl;
	logger->info("¬аш массив был отсортирован: " + forLog);
}

void ArrayBubble::bubbleSorter()
{
	for (int idOut = sizeArray - 1; idOut > 0; idOut--)
	{
		for (int idIn = 0; idIn < idOut; idIn++)
		{
			if (inArray[idIn] > inArray[idIn + 1])
			{
				logger->warning("Ёлемент массива: " + std::to_string(idIn) + ", будет заменен на элемент: " + std::to_string(idIn + 1));
				toSwap(idIn, idIn + 1);
			}
		}
	}
}

void ArrayBubble::toSwap(int first, int second)
{
	int dummy = inArray[first];
	inArray[first] = inArray[second];
	inArray[second] = dummy;
}
