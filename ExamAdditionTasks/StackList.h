#pragma once
template<class T>
class StackList : public Stack<T>
{
public:
	StackList()
	{
	};
	~StackList() {};
	virtual bool isEmpty()
	{
		return List.empty();
	};
	virtual bool isFull()
	{
		return false;
	};
	virtual T Pop()
	{
		if (!List.empty())
		{
			top = List.begin();
			return *top;
		}
		else
			throw MyStackIsEmtyProtectionExeption();
	};
	virtual void Push(T newelem)
	{
		List.push_front(newelem);
	};
private:
	list<T> List;//аналог "нашего списка"
	typename list<T>::iterator top;
};
