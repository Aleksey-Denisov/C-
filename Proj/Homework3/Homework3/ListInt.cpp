#include "ListInt.h"
#include <iostream>
#include <ctime>

ListInt::ListInt()
{
	srand(time(0));
	sizeArray = rand() % (30 - 10 + 1) + 10;
	intArray = new int[sizeArray];
	for (int idElement = 0; idElement < sizeArray; idElement++)
	{
		intArray[idElement] = rand() % (1000 - 10 + 1) + 10;;
	}
	printer();
	removeEvenNumbur();
}

ListInt::~ListInt()
{
	delete[] intArray;
	intArray = nullptr;
}

int ListInt::getIntRnd(int min, int max)
{
	return (rand() % (max - min + 1) + min);

}

void ListInt::removeEvenNumbur()
{
	int newSizeArray = getNewSizeArray();
	int* newIntArray = new int[newSizeArray];
	int currRecord = 0;
	for (int idElement = 0; idElement < sizeArray; idElement++)
	{
		if (intArray[idElement] % 2 != 0 && currRecord < newSizeArray)
		{
			newIntArray[currRecord] = intArray[idElement];
			currRecord++;
		}
	}
	delete[] intArray;
	intArray = nullptr;
	intArray = newIntArray;
	sizeArray = newSizeArray;
	printer();
	
}

int ListInt::getNewSizeArray()
{
	int newSizeArray = 0;
	for (int idElement = 0; idElement < sizeArray; idElement++)
	{
		if (intArray[idElement] % 2 != 0)
		{
			newSizeArray++;
		}
	}
	return newSizeArray;
}

void ListInt::printer()
{
	for (int idElement = 0; idElement < sizeArray; idElement++)
	{
		std::cout << intArray[idElement] << " ";
	}
	std::cout << std::endl;
}

int* ListInt::getArray()
{
	return intArray;
}

int ListInt::getSizeArray()
{
	return sizeArray;
}

void ListInt::findValues()
{
	int minValue = intArray[0], maxValue = intArray[0], average = 0;
	for (int idElement = 0; idElement < sizeArray; idElement++)
	{
		if (minValue > intArray[idElement])
			minValue = intArray[idElement];
		if (maxValue < intArray[idElement])
			maxValue = intArray[idElement];
		average += intArray[idElement];
	}
	std::cout << "ћаксимальное число: " << maxValue << ", минимальное число: " << minValue << ", среднее: " << (average / sizeArray) << std::endl;
}
