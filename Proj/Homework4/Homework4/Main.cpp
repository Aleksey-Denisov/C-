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
	ll.set(2, 84564);
	std::cout << ll.get(2) << std::endl;
	std::cout << "FOREACH:" << std::endl;
	//Фореч так себе, позже над ним подумаю. 
	//Не хочется делать много статики, так что пока это будет так. Просто счетчик
	for (int i : ll)
	{
		std::cout << ll.get(i) << " ";
	}
	std::cout << std::endl << "END" << std::endl;
	/*Реализуйте очередь с помощью LinkedList со следующими методами:
        enqueue() - помещает элемент в конец очереди - аналогичный метод add(), 
        dequeue() - возвращает первый элемент из очереди и удаляет его, 
        getfirst() - возвращает первый элемент из очереди, не удаляя.*/
	ll.add(test++);
	ll.addFirst(test++);
	std::cout << ll.dequeue() << std::endl;
	std::cout << ll.getFirst() << std::endl;
	ll.showAll();
	return 0;
}
