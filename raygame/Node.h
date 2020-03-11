#pragma once

template<typename T>
class Node
{
public:
	Node();
	~Node();

	T info;

	Node<T> * next;
	Node<T> * previous;
};

template<typename T>
inline Node<T>::Node()
{
}

template<typename T>
inline Node<T>::~Node()
{
}
