#pragma once
#include "List.h"

template<typename T>
class UnorderedList : List<T>
{
public:
	UnorderedList();
	~UnorderedList();

	void insertFirst(const T& first) override;
	void insertLast(const T& last) override;
};

