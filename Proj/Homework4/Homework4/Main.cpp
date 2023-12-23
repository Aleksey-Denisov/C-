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
	ll.set(2, 84564);
	/*Реализуйте очередь с помощью LinkedList со следующими методами:
        enqueue() - помещает элемент в конец очереди - аналогичный метод add(), 
        dequeue() - возвращает первый элемент из очереди и удаляет его, 
        getfirst() - возвращает первый элемент из очереди, не удаляя.*/
	ll.add(test++);
	ll.addFirst(test++);
	std::cout << ll.dequeue() << std::endl;
	std::cout << ll.getFirst() << std::endl;
	std::cout << "FOREACH:" << std::endl;
	for (int elList : ll)
	{
		std::cout << elList << " ";
	}
	std::cout << std::endl << "END" << std::endl;

	// Тесты номер 2
	LinkedList<std::string> lls = LinkedList<std::string>();
	lls.add("Hello world!");
	lls.add("Simple line");
	lls.add("Hard hyper line");
	lls.add("Don't worry");
	lls.fliplist();
	lls.set(1, " -There was text here- ");
	std::cout << lls.dequeue() << std::endl;
	std::cout << lls.getFirst() << std::endl;
	lls.addFirst("Happy b-day!");
	std::cout << "FOREACH:" << std::endl;
	for (const auto& str : lls)
	{
		std::cout << str << std::endl;
	}
	std::cout << "END" << std::endl;

	// Простенький LinkedList работает, а большего и не надо.
	return 0;
}


