#pragma once
#include "EnteringUserData.h"
#include "Logger.h"

class ArrayBubble
{

private:
	int sizeArray;
	int* inArray;
	std::string forLog = "";
	EnteringUserData enterUserData = EnteringUserData();
	Logger* logger;
	void toSwap(int first, int second);

public:
	ArrayBubble(const std::string& path);
	~ArrayBubble();
	void printer();
	void bubbleSorter();
};

