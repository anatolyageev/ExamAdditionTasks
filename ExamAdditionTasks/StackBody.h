#pragma once
#include "StackArray.h"
#include "StackList.h"
template<class T>
class StackBody : public Stack<T>
{

public:

	Stack<T> *Body;
	StackBody(int size)
	{

		Body = new StackArray<T>(size);
	};


	StackBody()
	{
		Body = new StackList<T>;
	};

	virtual void Push(T items)
	{
		Body->Push(items);
	};
	virtual T Pop()
	{
		return Body->Pop();
	};
	virtual bool isEmpty()
	{
		return Body->isEmpty();
	};
	virtual bool isFull()
	{
		return Body->isFull();
	};
};
