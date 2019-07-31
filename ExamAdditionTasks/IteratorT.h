#pragma once

template<class T>
class IteratorT
{
public:
	virtual bool hasNext() = 0;
	virtual T current() = 0;
	virtual T begin() = 0;
	virtual T end() = 0;
};
