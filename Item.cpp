#include "Global.h"

namespace krt
{// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Item~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Item::Item(vector<int> a, vector<int> b, vector<int> res, int line, int size)
	{
		this->_a = a;
		this->_b = b;
		this->_res = res;
		this->_line = line;
		this->_size = size;
	}
	Item::~Item()
	{
		_a.clear();
		_b.clear();
		_res.clear();
	}

	vector<int>& Item::getA()
	{
		return this->_a;
	}

	vector<int>& Item::getB()
	{
		return this->_b;
	}

	vector<int>& Item::getRES()
	{
		return this->_res;
	}

	int Item::getSize()
	{
		return this->_size;
	}

	int Item::getLINE()
	{
		return this->_line;
	}

	void Item::setline(int line)
	{
		this->_line = line;
	}

	void Item::setSize(int n)
	{
		this->_size = n;
	}
}