#pragma once
#include "IteratorT.h"
#include<iostream>
#include<string>

using namespace std;

template<class T>
class ListT : public IteratorT<T>
{
private:
	void deleteList(ListT* pFirst) {
		ListT* pCurrent = pFirst;
		while (pCurrent != NULL)
		{
			ListT* tmp = pCurrent;//временная перменная указатель
			pCurrent = pCurrent->pNext;
			delete tmp;//удалили весь элемент списка через временный указатель
		}
	}
	void createList(ListT*& pFirst, int size = 5) {
		int counter;
		pFirst = new ListT();
		//pFirst->info = 1;
		pFirst->pNext = NULL;
		pFirst->pPrev = NULL;
		pLast = pFirst;
		counter = 1;
		ListT* pCurrent = pFirst;
		while (counter < size)
		{
			ListT* pNew = new ListT();
			counter++;
			//pNew->info = counter;
			pNew->pNext = NULL;
			pNew->pPrev = NULL;
			pCurrent->pNext = pNew;
			pNew->pPrev = pCurrent;
			pCurrent = pNew;
			pLast = pCurrent;
		}
		pCurrentIt = pFirst;
	}
	ListT* createList(int size) {
		createList(this->pFirst);
		return this->pFirst;
	}
protected:
	T info;
	ListT* pNext;//pointer on next
	ListT* pPrev;//указатель на предыдущий
	ListT* pFirst, *pLast;//pFirst, pBeg, pBegin, pEnd, pTail(хвост)
	int size;
	//
	ListT()
	{
		//this->info = 0;
		this->pFirst = NULL;
		this->pLast = NULL;
		this->pNext = NULL;
		this->pPrev = NULL;
	}
	ListT(const ListT& obj) {}
	ListT* pCurrentIt;
	//
public:
	
	virtual bool hasNext() {
		if (pCurrentIt != NULL)
			return true;
		else
			return false;
	}
	T current() {
		T curvalue = pCurrentIt->info;
		pCurrentIt = pCurrentIt->pNext;
		return curvalue;
	}
	T begin() {
		return pFirst->info;
	}
	T end() {
		return pLast->info;
	}
	friend ostream&	operator << (ostream& os, const ListT& t) {
		ListT* pCurrent = t.pFirst;
		while (pCurrent != NULL)
		{
			os << pCurrent->info << endl;
			pCurrent = pCurrent->pNext;
		}
		return os;
	}

	ListT(int size) {
		this->size = size;
		this->pFirst = createList(this->size);
	}
	~ListT()
	{
		deleteList(pFirst);
	}
	ListT* getItem(int index)
	{
		if (index > this->size)
			return NULL;
		int counter = 1;
		ListT* pCurrent = pFirst;
		while (pCurrent != NULL)
		{
			if (counter == index)
			{
				return pCurrent;
			}
			pCurrent = pCurrent->pNext;
			counter++;
		}
	}
	T getValue(int index)
	{
		ListT* pItem = getItem(index);
		if (pItem != NULL)
			return pItem->info;
		else
			return 0;
	}
	void addAfter(int index, T value)
	{
		ListT* pCurrent = getItem(index);
		if (pCurrent != NULL)
		{
			ListT* pNew = new ListT();
			pNew->info = value;
			pNew->pPrev = pCurrent;
			pNew->pNext = pCurrent->pNext;
			pCurrent->pNext = pNew;
		}
	}

};


