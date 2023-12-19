#pragma once
#include "EnteringUserData.h"
class ArrayMerge
{

private:
	int* intArray;
	int sizeArray;
	bool flag = true;
	EnteringUserData userData = EnteringUserData();
	int* mergeSorter(int* tempArrayA, int sizeA);
	int* mergeArray(int* tempArrayA, int* tempArrayB, int sizeA, int sizeB);
	void printer(int* tempArray);
	void deleterArray(int* arr);

public:
	ArrayMerge();
	ArrayMerge(int* intArray, int sizeArray);
	~ArrayMerge();
	void startSorter();
};

