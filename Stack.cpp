#include "Global.h"

namespace krt
{
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Stack::Stack() : TOP(nullptr)
	{
		MakeEmpty();
	}

	Stack::~Stack()
	{
		this->MakeEmpty();
	}

	void Stack::push(Item data)
	{
		nodeStack* temp;
		temp = new nodeStack(data, TOP);
		this->TOP = temp;

	}

	Item Stack::pop()
	{
		Item temp;
		if (this->TOP == nullptr)
		{
			cout << "ERROR, THE STACK IS EMPTY" << endl;
		}
		else
		{
			temp = TOP->X;
			TOP = TOP->_next;
			return temp;
		}
	}

	bool Stack::isEmpty()
	{
		return (TOP == nullptr);
	}

	void Stack::MakeEmpty()
	{
		while (!this->isEmpty())
		{
			this->pop();
		}
	}
}
