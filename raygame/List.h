#pragma once
#include "Node.h"

template<typename T> 
class List
{

protected:

	int m_count;
	Node<T>* m_first;
	Node<T>* m_last;

	bool isEmpty

public:

	List();
	~List();
	int length();
	void front();
	void back();
	void insertFirst(const T&);
	void insertLast(const T&);
	void push(Node* head_ref, T NewDate);
	void pushBack(Node<T>* head_ref, T NewDate)

};

template<class T>
void List<T>::front()
{
	return startPtr;
}

template<class T>
void List<T>::back()
{
	return endptr;
}

template<class T>
void List<T>::insertFirst(const T &)
{
	if (isEmpty())
	{
		startPtr = newPtr;
		endptr = newPtr;
	}
	else
	{
		Node<T>* newPtr = new Node<>(dataIn);

		startPtr = newPtr;
		endptr = newPtr;
	}

}


template<class T>
void List<T>::insertLast(const T &)
{
	if (isEmpty())
	{
		startPtr = newPtr;
		endptr = newPtr;
	}
	else
	{

		Node<T>* newPtr = new Node<>(dataIn);

		startPtr = newPtr;
		endptr = newPtr;
	}
}

template<class T>
void List<T>::push(Node<T>* head_ref, T NewDate)
{
	Node new_node = new Node();

	new_node->Node<T> = NewDate;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

template<class T>
void List<T>::pushBack(Node<T>* End_ref, T NewDate)
{
	Node new_node = new Node();

	new_node->Node<T> = NewDate;

	new_node->next = (*End_ref);

	(*End_ref) = new_node;
}

