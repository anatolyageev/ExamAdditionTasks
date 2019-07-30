// ExamAdditionTasks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ListInt.h"
#include "VectorInt.h"
#include "StackBody.h"



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
