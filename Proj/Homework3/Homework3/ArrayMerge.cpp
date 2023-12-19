#include "ArrayMerge.h"
#include <string>
#include <iostream>

ArrayMerge::ArrayMerge()
{
	sizeArray = userData.enterInt("Введи размер массива: ");
	intArray = new int[sizeArray];
	for (int element = 0; element < sizeArray; element++)
	{
		intArray[element] = userData.enterInt("Введи число в элемент массива " + std::to_string(element) + ": ");
	}
}

ArrayMerge::ArrayMerge(int* intArray, int sizeArray)
{
	this->intArray = intArray;
	this->sizeArray = sizeArray;
	flag = false;
}

ArrayMerge::~ArrayMerge()
{
	//Если передача была по второму конструктору, то удалять указатель и массив не имеет смысла, удалится при выходе в корневом объекте
	if (flag)
	{
		delete[] intArray;
		intArray = nullptr;
	}
}

void ArrayMerge::startSorter()
{
	printer(mergeSorter(intArray, sizeArray));
}

int* ArrayMerge::mergeSorter(int* tempArrA, int sizeA)
{
	if (sizeA < 2)
	{
		return tempArrA;
	}
	int sizeB = sizeA / 2;
	int sizeC = sizeA - (sizeA / 2);
	int* tempArrB = new int[sizeB];
	int* tempArrC = new int[sizeC];
	for (int element = 0; element < sizeB; element++)
	{
		tempArrB[element] = tempArrA[element];
	}
	int tempElement = 0;
	for (int element = sizeB; element < sizeA; element++)
	{
		if (tempElement < sizeC)
		{
			tempArrC[tempElement] = tempArrA[element];
			tempElement++;
		}
	}
	int* arrB  = mergeSorter(tempArrB, sizeB);
	int* arrC = mergeSorter(tempArrC, sizeC);
	int* result = mergeArray(arrB, arrC, sizeB, sizeC);
	//Очистка места всех массивов, если длина не равна 1, так как дважды чистить указатели нельзя
	deleterArray(tempArrB);
	deleterArray(tempArrC);
	if (sizeB > 1)
		deleterArray(arrB);
	if (sizeC > 1)
		deleterArray(arrC);
	return result;
}

int* ArrayMerge::mergeArray(int* tempArrA, int* tempArrB, int sizeA, int sizeB)
{
	int* tempArrC = new int[sizeA + sizeB];
	int positionA = 0, positionB = 0, idElementArray = 0;
	while (positionA < sizeA && positionB < sizeB) {
		if (tempArrA[positionA] <= tempArrB[positionB]) {
			tempArrC[idElementArray++] = tempArrA[positionA++];
		}
		else {
			tempArrC[idElementArray++] = tempArrB[positionB++];
		}
	}
	while (positionA < sizeA) {
		tempArrC[idElementArray++] = tempArrA[positionA++];
	}
	while (positionB < sizeB) {
		tempArrC[idElementArray++] = tempArrB[positionB++];
	}
	return tempArrC;
}

void ArrayMerge::printer(int* tempArray)
{
	std::string forLog = "";
	for (int idElement = 0; idElement < sizeArray; idElement++)
	{
		forLog += std::to_string(tempArray[idElement]) + " ";
	}
	deleterArray(tempArray);
	std::cout << "Отсоритированный массив: " << forLog << std::endl;
}

void ArrayMerge::deleterArray(int* arr)
{
	delete[] arr;
	arr = nullptr;
}
