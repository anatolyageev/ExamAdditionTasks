#include "pch.h"
#include "ListInt.h"


bool ListInt::hasNext()
{
	if (pCurrentIt != NULL)
		return true;
	else
		return false;
}

int ListInt::current()
{

	int curvalue = pCurrentIt->info;
	pCurrentIt = pCurrentIt->pNext;
	return curvalue;
}

int ListInt::begin()
{
	return pFirst->info;
}

int ListInt::end()
{
	return pLast->info;
}

void ListInt::printListFromFirstToLast(ListInt* pFirst)
{
	ListInt* pCurrent = pFirst;
	while (pCurrent != NULL)
	{
		cout << pCurrent->info << endl;
		pCurrent = pCurrent->pNext;//сдвинул текущий на следующий элемент
	}
}
void ListInt::printListFromLastToFirst(ListInt* pLast)
{
	ListInt* pCurrent = pLast;
	while (pCurrent != NULL)
	{
		cout << pCurrent->info << endl;
		pCurrent = pCurrent->pPrev;//сдвинул текущий на предыдущий элемент
	}
}
void ListInt::deleteList(ListInt* pFirst)
{
	ListInt* pCurrent = pFirst;
	while (pCurrent != NULL)
	{
		ListInt* tmp = pCurrent;//временная перменная указатель
		pCurrent = pCurrent->pNext;
		delete tmp;//удалили весь элемент списка через временный указатель
	}
}
void ListInt::createList(ListInt*& pFirst, int size)
{
	int counter;
	pFirst = new ListInt();
	pFirst->info = 1;
	pFirst->pNext = NULL;
	pFirst->pPrev = NULL;
	pLast = pFirst;
	counter = 1;
	ListInt* pCurrent = pFirst;
	while (counter < size)
	{
		ListInt* pNew = new ListInt();
		counter++;
		pNew->info = counter;
		pNew->pNext = NULL;
		pNew->pPrev = NULL;
		pCurrent->pNext = pNew;
		pNew->pPrev = pCurrent;
		pCurrent = pNew;
		pLast = pCurrent;
	}
	pCurrentIt = pFirst;
}
ListInt* ListInt::createList(int size)
{
	createList(this->pFirst);
	return this->pFirst;
}

ostream & operator<<(ostream & os, const ListInt& t)
{
	ListInt* pCurrent = t.pFirst;
	while (pCurrent != NULL)
	{
		os << pCurrent->info << endl;
		pCurrent = pCurrent->pNext;
	}
	return os;
}
