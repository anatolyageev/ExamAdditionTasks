﻿// ExamAdditionTasks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ListInt.h"
#include "VectorInt.h"
#include "Stack.h"
#include "StackBody.h"
#include "ListT.h"
#include "VectorT.h"


class MyInfo
{
public:
	int age;
	string name;
	MyInfo()
	{
		name = "noname";
		age = 0;
	}
	friend ostream&	operator << (ostream& os, const MyInfo& t)
	{
		os << "name=" << t.name << "\nage=" << t.age << endl;
		os << endl;
		return os;
	}
};

int main()
{
	ListInt* list = new ListInt(5);
	cout << "Iterator working: " << endl;
	while (list->hasNext())
	{
		cout << list->current() << endl;
	};

	cout << "<< overridden: " << endl;
	cout << *list << endl;

	VectorInt *v1 = new VectorInt(3);
	//v1.print();
	cout << *v1;
	cout << "Indexation in Vector working: " << endl;
	cout << v1[0] << endl;
	cout << "Iterator in Vector working: " << endl;
	//cout << v1->current() << endl;
	while (v1->hasNext())
	{
		cout << v1->current() << endl;
	};
	cout << "Template list works : " << endl;
	ListT<MyInfo>* s5 = new ListT<MyInfo>(4);

	cout << *s5 << endl;

	cout << "Template Vector works : " << endl;

	VectorT<MyInfo>* vectorTest = new VectorT<MyInfo>(6);

	cout << *vectorTest << endl;

	
	Stack<MyInfo>* s = new StackBody<MyInfo>(10);//внутри будет создан стек через массив
	MyInfo M1;
	MyInfo i;
	cout << "Now List Stack:" << endl;
	s = new StackBody<MyInfo>();//внутри будет создан стек через список
	s->Push(M1);
	i = s->Pop();
	cout << i << endl;
	delete s;

	delete list;


	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
