#pragma once

//pieces of data that is put into lists
template<typename T>
class Node
{
public:
	//default constructor
	Node();
	//default deconstructor
	~Node();

	//the information that is stored in a node
	T info;

	//the node that is next in the list
	Node<T> * next;
	//the node that is previous in the list
	Node<T> * previous;
};

//default constructor
template<typename T>
inline Node<T>::Node()
{
}

//default deconstructor
template<typename T>
inline Node<T>::~Node()
{
}
