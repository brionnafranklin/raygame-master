#pragma once
#include "Node.h"


template<typename T>
//used to move through the list
class Iterator 
{
private:
	//declares a node
	Node<T>* currentNode;

public:
	//returns the next thing in the list
	Iterator<T> operator++(int);
	//returns the previous thing in the list
	Iterator<T> operator--(int);

	//returns the data at that point in the list
	T operator*();

	//default constructor
	Iterator();
	//default deconstructor
	~Iterator();
	//creates a pointer to the current node
	Iterator(Node<T>* ptr);

	//checks to see if the currentNode matches inputted another node
	bool operator==(const Iterator<T>&)const;
	//checks to see if the currentNode does not match another inputted node
	bool operator!=(const Iterator<T>&)const;
};

//returns the next thing in the list
template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	//if next node isn't null
	if (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
		//returns the next node
		return *this;
	}
	return nullptr;
}

//returns the previous thing in the list
template<typename T>
Iterator<T> Iterator<T>::operator--(int)
{
	//if previous node is not null
	if (currentNode->previous != nullptr)
	{
		currentNode = currentNode->previous;
		//returns the previous node
		return *this;
	}
	return nullptr;
}

template<typename T>
T Iterator<T>::operator*()
{
	return currentNode->info;
}

template<typename T>
Iterator<T>::Iterator()
{
	currentNode = nullptr;
}

template<typename T>
inline Iterator<T>::~Iterator()
{

}

template<typename T>
Iterator<T>::Iterator(Node<T>* ptr)
{
	currentNode = ptr;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& currentIterator) const
{
	if (currentNode != nullptr && currentIterator.currentNode != nullptr && &currentNode->info == &currentIterator.currentNode->info) return true;
	else return false;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& currentIterator) const
{
	if (currentNode == nullptr || currentIterator.currentNode == nullptr) return false;
	if (&currentNode->info != &currentIterator.currentNode->info) return true;
	else return false;
}
