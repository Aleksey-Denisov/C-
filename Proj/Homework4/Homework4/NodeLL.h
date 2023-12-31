#pragma once

template <typename E>
class NodeLL
{
private:
	E item;
	NodeLL<E>* next;
	NodeLL<E>* prev;
public:
	NodeLL(NodeLL<E>* prev, const E& element, NodeLL<E>* next);
	~NodeLL();
	NodeLL<E>* getPrev();
	NodeLL<E>* getNext();
	const E& getItem();
	void setNext(NodeLL<E>* next);
	void setPrev(NodeLL<E>* next);
	void setItem(const E& item);
	
};

template <typename E>
NodeLL<E>::NodeLL(NodeLL<E>* prev, const E& element, NodeLL<E>* next)
{
	this->item = element;
	this->next = next;
	this->prev = prev;
}

template <typename E>
NodeLL<E>::~NodeLL() { next = prev = nullptr; }

template <typename E>
NodeLL<E>* NodeLL<E>::getPrev() { return prev; }

template <typename E>
NodeLL<E>* NodeLL<E>::getNext() { return next; }

template <typename E>
const E& NodeLL<E>::getItem() { return item; }

template <typename E>
void NodeLL<E>::setNext(NodeLL<E>* next) { this->next = next; }

template <typename E>
void NodeLL<E>::setPrev(NodeLL<E>* prev) { this->prev = prev; }

template <typename E>
void NodeLL<E>::setItem(const E& item) { this->item = item; }
