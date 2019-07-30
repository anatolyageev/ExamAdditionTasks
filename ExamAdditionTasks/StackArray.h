#pragma once
template<class T>
class StackArray : public Stack<T>
{
public:
	StackArray(int sizestack);
	~StackArray();
	virtual bool isEmpty();
	virtual bool isFull();
	virtual T Pop();
	virtual void Push(T);
private:
	T* pArray;
	int pos;
	int size;
};
//

template<class T>
StackArray<T>::StackArray(int sizestack)
{
	pos = 0;
	pArray = new T[sizestack];
	size = sizestack;
}
template<class T>
StackArray<T>::~StackArray()
{
	delete pArray;
};
template<class T>
bool StackArray<T>::isEmpty()
{
	if (pos == 0)
		return true;
	else
		return false;
}
template<class T>
bool StackArray<T>::isFull()
{
	if (pos == size)
		return true;
	else
		return false;
}
template<class T>
T StackArray<T>::Pop()
{
	if (!this->isEmpty())
	{
		return pArray[--pos];
	}
	else
		throw MyStackIsEmtyProtectionExeption();


}
template<class T>
void StackArray<T>::Push(T newitems)
{


	if (!this->isFull())
	{
		pArray[pos++] = newitems;
	}
	else
		throw MyStackOverFlowProtectionExeption();

}

