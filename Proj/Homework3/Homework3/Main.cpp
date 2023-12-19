#include "ArrayMerge.h"
#include "ListInt.h"
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	//Реализовать алгоритм сортировки слиянием
	//ArrayMerge().startSorter();
	//Пусть дан произвольный список целых чисел, удалить из него четные числа
	ListInt li = ListInt();
	//Объединим две задачи в одну, ради эксперимента
	ArrayMerge(li.getArray(), li.getSizeArray()).startSorter();
	//Задан целочисленный список ArrayList. Найти минимальное, максимальное и среднее из этого списка.
	//Найдем в полученном списке без четных чисел
	li.findValues();
	return 0;
}