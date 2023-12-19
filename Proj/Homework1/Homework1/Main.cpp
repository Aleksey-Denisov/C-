#include "SumAndMulty.h"
#include "SimpleNumbers.h"
#include "SimpleCalculator.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	//Вычислить n-ое треугольного число(сумма чисел от 1 до n), n! (произведение чисел от 1 до n)
	SumAndMulty();
	//Вывести все простые числа от 1 до 1000
	SimpleNumbers();
	//Реализовать простой калькулятор
	SimpleCalculator();
	return 0;
}