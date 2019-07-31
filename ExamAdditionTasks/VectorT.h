#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include "IteratorT.h"
using namespace std;

template<class T>
class VectorT : public IteratorT<T>
{
	
	private:
		T* pArr;
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
		virtual T current()
		{
			T curvalue = pArr[currIndex];
			currIndex++;
			return curvalue;
		};

		virtual T begin() { return pArr[0]; };
		virtual T end() { return pArr[_size - 1]; };

		VectorT() {};
		VectorT(int size)
		{
			this->_size = size;
			pArr = new T[_size];
			for (int i = 0; i < size; i++)
			{
				pArr[i];
			}
			currIndex = 0;
		}
		~VectorT() { delete pArr; };


		int size()const {
			return this->_size;
		};

		friend ostream&	operator << (ostream& os, const VectorT& t) {
			os.precision(3);
			for (int i = 0; i < t._size; i++)
			{
				os << fixed << t.pArr[i] << " ";
			}
			os << endl;
			return os;
		}
		T& operator[](int i) {
			return pArr[i];
		}
		const T& operator[](int i) const {
			return pArr[i];
		}
};

