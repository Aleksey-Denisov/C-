#pragma once
#include "NodeLL.h"
#include <string>

template <typename E>
class LinkedList
{
private:
	int size = 0;
	int item = 0;
	NodeLL<E>* first = nullptr;
	NodeLL<E>* last = nullptr;

	void unlink(NodeLL<E>* x);

	void linkFirst(const E& e);
	void linkLast(const E& e);
	NodeLL<E>* node(const int& index);

	bool isElementIndex(const int& index);

	template<typename T>
	struct Iterator
	{
		T p;
		T& operator*() { return p; }
		bool operator !=(const Iterator& rhs) { return p != rhs.p; }
		void operator ++() { ++p; }
	};
public:

	~LinkedList();
	void clear();
	void remove(const int& index);
	const E& dequeue();

	void add(const E& e);
	void addFirst(const E& e);
	void set(const int& index, const E& e);
	void fliplist();
	const E& get(const int& index);
	const E& getFirst();
	auto begin();
	auto end();

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
}

template <typename E>
void LinkedList<E>::remove(const int& index)
{
	if (isElementIndex(index))
		unlink(node(index));
}

template <typename E>
const E& LinkedList<E>::dequeue()
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
	const E& element = x->getItem();
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
}

// Func deletes end


// Func changes begin

template <typename E>
void LinkedList<E>::add(const E& e) { linkLast(e); }

template <typename E>
void LinkedList<E>::addFirst(const E& e) { linkFirst(e); }

template <typename E>
void LinkedList<E>::linkFirst(const E& e)
{
	NodeLL<E>* f = first;
	NodeLL<E>* newNode = new NodeLL<E>(nullptr, e, f);
	first = newNode;
	if (f == nullptr)
		last = newNode;
	else
		f->setPrev(newNode);
	size++;
}

template <typename E>
void LinkedList<E>::linkLast(const E& e)
{
	NodeLL<E>* l = last;
	NodeLL<E>* newNode = new NodeLL<E>(l, e, nullptr);
	last = newNode;
	if (l == nullptr)
		first = newNode;
	else
		l->setNext(newNode);
	size++;
}

template <typename E>
void LinkedList<E>::set(const int& index, const E& e)
{
	if (isElementIndex(index))
	{
		NodeLL<E>* x = node(index);
		E oldval = x->getItem();
		x->setItem(e);
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
const E& LinkedList<E>::get(const int& index)
{ 
	if (isElementIndex(index))
		return node(index)->getItem();
	return node(size - 1)->getItem();
}

template <typename E>
const E& LinkedList<E>::getFirst()
{
	NodeLL<E>* f = first;
	if (f == nullptr)
		throw std::string{ "There are no items in the list" };
	return f->getItem();
}

template <typename E>
NodeLL<E>* LinkedList<E>::node(const int& index)
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
auto LinkedList<E>::begin()
{
	return Iterator<E>{item};
}

template <typename E>
auto LinkedList<E>::end()
{
	return Iterator<E>{size};
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
bool LinkedList<E>::isElementIndex(const int& index)
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
