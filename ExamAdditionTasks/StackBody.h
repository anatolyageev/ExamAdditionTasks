#pragma once
#include "Stack.h"
#include "ArrayStack.h"

template<class T>
class StackBody: public Stack<T>
{
protected:
	//Stack<T> *Body;
public:
	
	StackBody(int size)
	{
		
		this->Body = new ArrayStack<T>(size);
	};

	/*
	StackBody()
	{
		Body = new StackList<T>;
	};
*/
	virtual void Push(T items)
	{
		this->Body->Push(items);
	};
	virtual T Pop()
	{
		return this->Body->Pop();
	};
	virtual bool isEmpty()
	{
		return this->Body->isEmpty();
	};
	virtual bool isFull()
	{
		return this->Body->isFull();
	};
};

