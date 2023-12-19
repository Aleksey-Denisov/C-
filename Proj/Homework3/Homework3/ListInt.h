#pragma once
class ListInt
{

private:
	int* intArray;
	int sizeArray;
	int getIntRnd(int min, int max);
	int getNewSizeArray();
	void removeEvenNumbur();
	void printer();

public:
	ListInt();
	~ListInt();
	int* getArray();
	int getSizeArray();
	void findValues();
};

