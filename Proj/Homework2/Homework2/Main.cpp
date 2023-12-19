#include "EnteringUserData.h"
#include "ArrayBubble.h"
#include "SimpleCalculator.h"
#include <iostream>

int main() {
	setlocale(LC_CTYPE, "Russian");
	//Реализуйте алгоритм сортировки пузырьком числового массива, результат после каждой итерации запишите в лог-файл.
	ArrayBubble ab = ArrayBubble("logSorter");
	ab.bubbleSorter();
	ab.printer();
	ab.~ArrayBubble();
	//К калькулятору из предыдущего дз добавить логирование.
	SimpleCalculator("logSorter");
	return 0;
}