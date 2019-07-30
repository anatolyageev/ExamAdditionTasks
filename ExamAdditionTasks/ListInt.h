#pragma once
#include "Iterator.h"
#include<iostream>
#include<string>

using namespace std;
class ListInt: public Iterator
{
private:
	void deleteList(ListInt* pFirst);
	void createList(ListInt*& pFirst, int size = 5);
	ListInt* createList(int size);
protected:
	int info;
	ListInt* pNext;//pointer on next
	ListInt* pPrev;//указатель на предыдущий
	ListInt* pFirst, *pLast;//pFirst, pBeg, pBegin, pEnd, pTail(хвост)
	int size;
	void printListFromFirstToLast(ListInt* pFirst);
	void printListFromLastToFirst(ListInt* pLast);
	//
	ListInt()
	{
		this->info = 0;
		this->pFirst = NULL;
		this->pLast = NULL;
		this->pNext = NULL;
		this->pPrev = NULL;
	}
	ListInt(const ListInt& obj) {}
	ListInt* pCurrentIt;
	//
public:
	void print() {printListFromFirstToLast(this->pFirst);}
	void printReverse()	{printListFromLastToFirst(this->pLast);}

	virtual bool hasNext();
	int current();
	int begin();
	int end();

	friend ostream&	operator << (ostream& os, const ListInt& t);

	ListInt(int size){
		this->size = size;
		this->pFirst = createList(this->size);
	}
	~ListInt()
	{
		deleteList(pFirst);
	}
	ListInt* getItem(int index)
	{
		if (index > this->size)
			return NULL;
		int counter = 1;
		ListInt* pCurrent = pFirst;
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
	int getValue(int index)
	{
		ListInt* pItem = getItem(index);
		if (pItem != NULL)
			return pItem->info;
		else
			return 0;
	}
	void addAfter(int index, int value)
	{
		ListInt* pCurrent = getItem(index);
		if (pCurrent != NULL)
		{
			ListInt* pNew = new ListInt();
			pNew->info = value;
			pNew->pPrev = pCurrent;
			pNew->pNext = pCurrent->pNext;
			pCurrent->pNext = pNew;
		}
	}

};

