#pragma once
#include "List.h"

template<typename T>
class UnorderedList : List<T>
{
public:
	UnorderedList();
	~UnorderedList();

	insertFirst(const T&) override;
	insertLast(const T&) override;
};

template<typename T>
inline UnorderedList<T>::insertFirst(const T & Info)
{
	//Create a new Node
	Node<T> fNode;

	//Add info to the new node
	fNode.Info = Info;

	//Set the new nodes "next" to be the first node in the list
	fNode.Next = m_first;

	//Set First to point to the new node
	m_first = fNode;
}

template<typename T>
inline UnorderedList<T>::insertLast(const T & Info)
{
	//Crate a new Node
	Node<T> lNode;

	//Add info to the new Node
	lNode.Info = Info;

	//Set the new nodes "next" to be null in the list
	lNode.Next = nullptr;

	//Set Last to point to the new node
	m_last = lNode;
}

