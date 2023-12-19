#pragma once
#include "EnteringUserData.h"
#include "Logger.h"

class SimpleCalculator
{

private:
	double oneNumber = 0, twoNumber = 0;
	char operation;
	void perfAction();
	EnteringUserData enterUserData = EnteringUserData();
	Logger* logger;

public:
	SimpleCalculator(const std::string& path);
	~SimpleCalculator();
};

