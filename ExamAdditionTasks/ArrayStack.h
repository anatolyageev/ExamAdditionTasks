#pragma once
#include "Stack.h"


template<class T>
class ArrayStack : public Stack<T>
{
public:
	ArrayStack(int sizestack);
	~ArrayStack();
	virtual bool isEmpty();
	virtual bool isFull();
	virtual T Pop();
	virtual void Push(T);
private:
	T* pArray;
	int pos;
	int size;
};

