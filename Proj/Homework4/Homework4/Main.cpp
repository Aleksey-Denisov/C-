#include <iostream>
#include <string>
#include "LinkedList.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int test = 1;
	// ����� ��� LinkedList � ����������� ����������. ���������� �����, ������� ������ ������������� ������.
	LinkedList<int> ll = LinkedList<int>();
	ll.add(test++);
	ll.add(test++);
	ll.add(test++);
	ll.add(test++);
	ll.add(test++);
	ll.add(test++);
	ll.fliplist();
	ll.showAll();
	/*���������� ������� � ������� LinkedList �� ���������� ��������:
		enqueue() - �������� ������� � ����� �������, - ����������� ����� � ������ ���������� add()
		dequeue() - ���������� ������ ������� �� ������� � ������� ���,
		first() - ���������� ������ ������� �� �������, �� ������.*/
	ll.add(test++);
	std::cout << ll.dequeue() << std::endl;
	std::cout << ll.getFirst() << std::endl;
	ll.showAll();
	return 0;
}
