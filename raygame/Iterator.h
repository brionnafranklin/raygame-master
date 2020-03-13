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

//returns the data at that point in the list
template<typename T>
T Iterator<T>::operator*()
{
	//return the info at the current node
	return currentNode->info;
}

//default constructor
template<typename T>
Iterator<T>::Iterator()
{
	//sets currentNode to null
	currentNode = nullptr;
}

//default deconstructor
template<typename T>
inline Iterator<T>::~Iterator()
{
}

//creates a pointer to the current node
template<typename T>
Iterator<T>::Iterator(Node<T>* ptr)
{
	//sets currentNode to ptr
	currentNode = ptr;
}

//checks to see if the currentNode matches inputted another node
template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& currentIterator) const
{
	//if currentNode isn't null and currentIterator.currentNode isn't null and the info of both match
	if (currentNode != nullptr && currentIterator.currentNode != nullptr && &currentNode->info == &currentIterator.currentNode->info) return true;
	else return false;
}

//checks to see if the currentNode does not match another inputted node
template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& currentIterator) const
{
	//if either are null return false
	if (currentNode == nullptr || currentIterator.currentNode == nullptr) return false;
	//if the infos do not match
	if (&currentNode->info != &currentIterator.currentNode->info) return true;
	else return false;
}
