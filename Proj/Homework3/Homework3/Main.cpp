#include "ArrayMerge.h"
#include "ListInt.h"
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	//����������� �������� ���������� ��������
	//ArrayMerge().startSorter();
	//����� ��� ������������ ������ ����� �����, ������� �� ���� ������ �����
	ListInt li = ListInt();
	//��������� ��� ������ � ����, ���� ������������
	ArrayMerge(li.getArray(), li.getSizeArray()).startSorter();
	//����� ������������� ������ ArrayList. ����� �����������, ������������ � ������� �� ����� ������.
	//������ � ���������� ������ ��� ������ �����
	li.findValues();
	return 0;
}