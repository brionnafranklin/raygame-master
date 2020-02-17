#pragma once
#include "Node.h"

template<typename T> 
class List
{

protected:

	int m_count;
	Node<T>* m_first;
	Node<T>* m_last;

public:
	List();
	List(List<T>&)
	~List();

	//int Length();

	T front();
	T back();

	//virtual bool search(const T&) = 0;
	virtual void insertFirst(const T& first) = 0;
	virtual void insertLast(const T& last) = 0;
	//virtual void deleteNode(const T&) = 0;

	//iterator<T> Begin();
	//iterator<T> End();

	bool isEmpty();

private:
	//void copyList(List<T> &)
};

