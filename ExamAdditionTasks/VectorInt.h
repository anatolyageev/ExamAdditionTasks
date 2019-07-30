#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include "Iterator.h"
using namespace std;


class VectorInt: public Iterator
{
private:
	int* pArr;
protected:
	int _size;
	int currIndex;
public:

	virtual bool hasNext()
	{
		if (currIndex >= 0 && currIndex <= _size - 1)
			return true;
		if (currIndex < 0 || currIndex > _size - 1)
			return false;
	};
	virtual int current()
	{
		int curvalue = pArr[currIndex];
		currIndex++;
		return curvalue;
	};
	
	virtual int begin() { return pArr[0]; };
	virtual int end() { return pArr[_size - 1]; };

	VectorInt() {};
	VectorInt(int size)
	{
		this->_size = size;
		pArr = new int[_size];
		for (int i = 0; i < size; i++)
		{
			pArr[i] = 0;
		}
		currIndex = 0;
	}
	~VectorInt() { delete pArr; };
	

	int size()const;

	friend ostream&	operator << (ostream& os, const VectorInt& t);
	int& operator[](int);//извлечение для оператора присвоения
	const int& operator[](int i) const;//извлечение для вывода

	
};

