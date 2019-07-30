#include "pch.h"
#include "VectorInt.h"


int& VectorInt::operator[](int i)
{
	return pArr[i];
};

const int& VectorInt::operator[](int i)const
{
	return pArr[i];
};

ostream& operator<<   (ostream& os, const VectorInt& t)
{
	os.precision(3);
	for (int i = 0; i < t._size; i++)
	{
		os << fixed << t.pArr[i] << " ";
	}
	os << endl;
	return os;
}
//
int VectorInt::size()const
{
	return this->_size;
};

