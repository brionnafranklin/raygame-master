#pragma once
#include "Node.h"
#include "Iterator.h"

//holds data
template<typename T>
class List {
protected:
	//used to keep tract of posistion in the list
	int mCount;

	//the last spot in the list
	Node<T>* m_last;
	//the first spot in the list
	Node<T>* m_first;

public:
	//set everything in list to nothing
	void initializeList();
	//checks to see if list is empty
	bool isListEmpty();
	//used to keep tract of how long the list is
	int length();

	//returns the info in the first spot of the list
	T front();
	//returns the info in the last spot of the list
	T back();

	//returns true if node is found
	virtual bool search(const T&) = 0;
	//adds a node to the beginning of the list
	virtual void insertFirst(const T&) = 0;
	//adds a node to the end of the list
	virtual void insertLast(const T&) = 0;
	//deletes a node
	virtual void deleteNode(const T&) = 0;

	//iterates through the list starting with the beginning
	Iterator<T> begin();
	//iterates through the list starting with the beginning
	Iterator<T> end();

	//default constructor
	List();
	//default deconstructor
	~List();

private:
	//copies contents of list
	void copyList(List<T>&);
};

//set everything in list to nothing
template<typename T>
void List<T>::initializeList()
{
	//set first and last to null
	m_first = nullptr;
	m_last = nullptr;
	//set mCount to 0
	mCount = 0;
}

//checks to see if list is empty
template<typename T>
bool List<T>::isListEmpty()
{
	//if the first spot is empty
	if (m_first == nullptr) return true;
	else return false;
}

//used to keep tract of how long the list is
template<typename T>
int List<T>::length()
{
	//returns length of the list
	return mCount;
}

//returns the info in the first spot of the list
template<typename T>
T List<T>::front()
{
	//returns info at the front of the list
	return m_first->info;
}

//returns the info in the last spot of the list
template<typename T>
T List<T>::back()
{
	//returns info at the back of the list
	return m_last->info;
}

//iterates through the list starting with the beginning
template<typename T>
Iterator<T> List<T>::begin()
{
	//iterates the list startinf eith the first node
	return Iterator<T>(m_first);;
}

//iterates through the list starting with the beginning
template<typename T>
Iterator<T> List<T>::end()
{
	//iterates the list startinf eith the last node
	return Iterator<T>(m_last);
}

//default constructor
template<typename T>
List<T>::List()
{
	//set everything to 0
	initializeList();
}

//default deconstructor
template<typename T>
List<T>::~List()
{
}

//copies contents of list
template<typename T>
void List<T>::copyList(List<T>& listToCopy)
{
	//populate new list
	this->m_first = &(*listToCopy->m_first);
	this->m_last = &(*listToCopy->m_last);
	//make lengths the same
	mCount = listToCopy.length();
	//delete old list
	delete listToCopy;
}
