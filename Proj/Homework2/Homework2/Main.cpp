#include "EnteringUserData.h"
#include "ArrayBubble.h"
#include "SimpleCalculator.h"
#include <iostream>

int main() {
	setlocale(LC_CTYPE, "Russian");
	//���������� �������� ���������� ��������� ��������� �������, ��������� ����� ������ �������� �������� � ���-����.
	ArrayBubble ab = ArrayBubble("logSorter");
	ab.bubbleSorter();
	ab.printer();
	ab.~ArrayBubble();
	//� ������������ �� ����������� �� �������� �����������.
	SimpleCalculator("logSorter");
	return 0;
}