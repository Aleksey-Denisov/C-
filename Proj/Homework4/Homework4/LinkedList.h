#pragma once
#include "NodeLL.h"
#include <string>

template <typename E>
class LinkedList
{
private:
	int size = 0;
	int modCount = 0;
	NodeLL<E>* first = nullptr;
	NodeLL<E>* last = nullptr;

	void unlink(NodeLL<E>* x);

	void linkFirst(E e);
	void linkLast(E e);
	NodeLL<E>* node(int index);

	bool isElementIndex(int index);
public:

	~LinkedList();
	void clear();
	void remove(int index);
	E dequeue();

	void add(E e);
	void addFirst(E e);
	void set(int index, E e);
	void fliplist();
	E get(int index);
	E getFirst();

	void showAll();
	int sizeLL();

};

// Func deletes begin

template <typename E>
LinkedList<E>::~LinkedList() { clear(); }

template <typename E>
void LinkedList<E>::clear()
{
	for (NodeLL<E>* x = first; x != nullptr; )
	{
		NodeLL<E>* nextNode = x->getNext();
		x->~NodeLL();
		x = nextNode;
	}
	first = last = nullptr;
	size = 0;
	modCount++;
}

template <typename E>
void LinkedList<E>::remove(int index)
{
	if (isElementIndex(index))
		unlink(node(index));
}

template <typename E>
E LinkedList<E>::dequeue()
{
	NodeLL<E>* f = first;
	if (f == nullptr)
		throw std::string{ "There are no items in the list" };
	E element = f->getItem();
	unlink(f);
	return element;
}

template <typename E>
void LinkedList<E>::unlink(NodeLL<E>* x)
{
	E element = x->getItem();
	NodeLL<E>* next = x->getNext();
	NodeLL<E>* prev = x->getPrev();
	if (prev == nullptr)
	{
		first = next;
	}
	else
	{
		prev->setNext(next);
		x->setPrev(nullptr);
	}

	if (next == nullptr)
	{
		last = prev;
	}
	else
	{
		next->setPrev(prev);
		x->setNext(nullptr);
	}
	size--;
	modCount++;
}

// Func deletes end


// Func changes begin

template <typename E>
void LinkedList<E>::add(E e) { linkLast(e); }

template <typename E>
void LinkedList<E>::addFirst(E e) { linkFirst(e); }

template <typename E>
void LinkedList<E>::linkFirst(E e)
{
	NodeLL<E>* f = first;
	NodeLL<E>* newNode = new NodeLL<E>(nullptr, e, f);
	first = newNode;
	if (f == nullptr)
		last = newNode;
	else
		f->setPrev(newNode);
	size++;
	modCount++;
}

template <typename E>
void LinkedList<E>::linkLast(E e)
{
	NodeLL<E>* l = last;
	NodeLL<E>* newNode = new NodeLL<E>(l, e, nullptr);
	last = newNode;
	if (l == nullptr)
		first = newNode;
	else
		l->setNext(newNode);
	size++;
	modCount++;
}

template <typename E>
void LinkedList<E>::set(int index, E e)
{
	if (isElementIndex(index))
	{
		NodeLL<E>* x = node(index);
		E oldval = x->getItem();
		x->setItem(e);
	}
}

template <typename E>
NodeLL<E>* LinkedList<E>::node(int index)
{
	if (index < size && size > 1) {
		NodeLL<E>* x = first;
		for (int i = 0; i < index; i++)
			x = x->getNext();
		return x;
	}
	else {
		NodeLL<E>* x = last;
		for (int i = size - 1; i > index; i--)
			x = x->getPrev();
		return x;
	}
}

template <typename E>
void LinkedList<E>::fliplist()
{
	for (int elBeg = 0, elEnd = sizeLL() - 1; elBeg < elEnd; elBeg++, elEnd--)
	{
		E beg = get(elBeg);
		set(elBeg, get(elEnd));
		set(elEnd, beg);
	}
}

// Func changes end

// Func getters begin

template <typename E>
E LinkedList<E>::get(int index) 
{ 
	if (isElementIndex(index))
		return node(index)->getItem();
	return node(size - 1)->getItem();
}

template <typename E>
E LinkedList<E>::getFirst()
{
	NodeLL<E>* f = first;
	if (f == nullptr)
		throw std::string{ "There are no items in the list" };
	return f->getItem();
}

template <typename E>
void LinkedList<E>::showAll()
{
	for (int elBeg = 0; elBeg < size; elBeg++)
	{
		std::cout << get(elBeg) << " ";
	}
	std::cout << std::endl;
}

template <typename E>
int LinkedList<E>::sizeLL() { return size; }

template <typename E>
bool LinkedList<E>::isElementIndex(int index) 
{
	try
	{
		if (index >= 0 && index < size)
			return true;
		else
			throw std::string{ "You are outside the allowed range of the list: " + std::to_string(index) + ", size array: " + std::to_string(size) };
	}
	catch (const std::string& error)
	{
		std::cout << error << std::endl;
	}
	return false;
}

// Func getters end
