#pragma once
template<class T>
class Stack
{
protected:
	Stack *Body;
public:
	virtual void Push(T) = 0;
	virtual T Pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
};
