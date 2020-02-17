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

private:

};
