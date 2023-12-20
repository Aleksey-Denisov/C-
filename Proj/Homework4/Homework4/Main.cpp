#include <iostream>
#include <string>
#include "LinkedList.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int test = 1;
	// Пусть дан LinkedList с несколькими элементами. Реализуйте метод, который вернет “перевернутый” список.
	LinkedList<int> ll = LinkedList<int>();
	ll.add(test++);
	ll.add(test++);
	ll.add(test++);
	ll.add(test++);
	ll.add(test++);
	ll.add(test++);
	ll.fliplist();
	ll.showAll();
	/*Реализуйте очередь с помощью LinkedList со следующими методами:
		enqueue() - помещает элемент в конец очереди, - аналогичный метод в данной реализации add()
		dequeue() - возвращает первый элемент из очереди и удаляет его,
		first() - возвращает первый элемент из очереди, не удаляя.*/
	ll.add(test++);
	std::cout << ll.dequeue() << std::endl;
	std::cout << ll.getFirst() << std::endl;
	ll.showAll();
	return 0;
}
