#pragma once
#include <iostream>
#include "List.h"

//list that is not ordered
template<typename T>
class UnorderedList : public List<T> {
public:
	//returns true if node is found
	bool search(const T&);
	//adds a node to the beginning of the list
	void insertFirst(const T&);
	//adds a node to the end of the list
	void insertLast(const T&);
	//deletes a node
	void deleteNode(const T&);
	//removes everything in the list
	void clear();
};

//returns true if node is found
template<typename T>
bool UnorderedList<T>::search(const T& infoToSearch)
{
	//check for same info in first and last position
	if (this->m_first->info == infoToSearch) return true;
	if (this->m_last->info == infoToSearch) return true;
	//check all nodes for a matches
	for (auto i = this->begin(); i != this->end(); i++)
	{
		//return true if found
		if (*i == infoToSearch) return true;
	}
	return false;
}

//deletes a node
template<typename T>
void UnorderedList<T>::deleteNode(const T& infoToDelete)
{
	Node<T>* iter = &(*this->m_first);

	//checks to if the first node is being deleted
	if (this->m_first->info == infoToDelete)
	{
		//if the list only has 1 node
		if (this->length() == 1)
		{
			//set first and last to null
			this->m_first = nullptr;
			this->m_last = nullptr;
			//delete the node made at the beginning of the function
			delete iter;
			//make mCount 1 less
			this->mCount--;
			return;
		}
		//make the first thing the next thing of iter
		this->m_first = iter->next;
		//delete the node made at the beginning of the function
		delete iter;
		//make mCount 1 less
		this->mCount--;
		return;
	}
	//checks to if the last node is being deleted
	if (this->m_last->info == infoToDelete)
	{
		iter = &(*this->m_last);
		//set the last thing to be the previous thing of iter
		this->m_last = iter->previous;
		//delete the node made at the start of the function
		delete iter;
		//make mCount 1 less
		this->mCount--;
		return;
	}

	//keeps track of which spot it is currently on
	int spotInList = 1;
	for (auto i = this->begin(); i != this->end(); i++)
	{
		//if node needs to be deleted and the SpotInList is not 0/ the length of the list
		if ((*i) == infoToDelete && spotInList != 0 && spotInList != this->length())
		{
			//makes the next previous spot the previous spot
			iter->next->previous = iter->previous;
			//makes the previous next spot the next spot
			iter->previous->next = iter->next;
			//delete the node made at the start of the function
			delete iter;
			//make mCount 1 less
			this->mCount--;
			break;
		}
		else
		{
			//go to next spot
			spotInList++;
			iter = &(*iter->next);
		}
	}
}

//removes everything in the list
template<typename T>
void UnorderedList<T>::clear()
{
	//Can override [] for iterating through instead of this
	iterate through list
	for (int i = this->mCount; i > 0; i--)
	{
		//make iter the fist thing in the list
		Node<T>* iter = this->m_first;
		//make the node after iter = null
		Node<T>* iterNext = nullptr;

		//if the node after iter is noy null
		if (iter->next != nullptr)
		{
			//set iterNext to the node after iter
			iterNext = iter->next;
		}

		//delete the info stored in iter
		this->deleteNode(iter->info);

		//if iterNext is not null
		if (iterNext != nullptr)
		{
			//iter is set to the value of iterNext
			iter = iterNext;
		}
	}
}

//adds a node to the beginning of the list
template<typename T>
void UnorderedList<T>::insertFirst(const T& tempInfo)
{
	//make new node
	Node<T>* newNode = new Node<T>;
	//put the inputted ifo into the new node
	newNode->info = tempInfo;

	//if the list is empty
	if (this->isListEmpty())
	{
		//first and last is the newnode
		this->m_first = newNode;
		this->m_last = newNode;
		//increse mCount by 1
		this->mCount++;
		return;
	}
	//make the first node the next node of the new node
	newNode->next = this->m_first;
	//make the previous node of the first node the new node
	this->m_first->previous = newNode;
	//make the first node the new node
	this->m_first = newNode;
	//make the previous node of the new node null
	newNode->previous = nullptr;
	//increse mCount by 1
	this->mCount++;
}

//adds a node to the end of the list
template<typename T>
void UnorderedList<T>::insertLast(const T& tempInfo)
{
	//make new node
	Node<T>* newNode = new Node<T>;
	//set the new node's info to the inputted info
	newNode->info = tempInfo;

	//if the the last spot in the list is nill
	if (this->m_last == nullptr)
	{
		//make the first spot the new node
		this->m_first = newNode;
		//make the last spot the new node
		this->m_last = newNode;
		//increse mCount by 1
		this->mCount++;
		return;
	}
	//make the next of the last node the new node
	this->m_last->next = newNode;
	//make the previous of the new node the last node
	newNode->previous = this->m_last;
	//make the last node the new node
	this->m_last = newNode;
	//make the next node of the new node null
	newNode->next = nullptr;
	//increse mCount by 1
	this->mCount++;
}
