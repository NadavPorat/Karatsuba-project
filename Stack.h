#pragma once

namespace krt
{
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~nodeStack~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	class nodeStack
	{
		friend class Stack;
	private:
		nodeStack* _next;
		Item X;
	public:
		nodeStack(Item& item, nodeStack* next) :X(item), _next(next) {}
	};

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STACK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	class Stack
	{
	private:
		nodeStack* TOP;
	public:
		Stack();
		~Stack();
		void push(Item data);
		Item pop();
		bool isEmpty();
		void MakeEmpty();
	};
}
