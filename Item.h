#pragma once

namespace krt
{
	class Item
	{
		friend class nodeStack;
	private:
		vector<int> _a;
		vector<int> _b;
		vector<int> _res;
		int _size = 0;
		int _line = 0;
	public:
		Item() = default;
		Item(vector<int> a, vector<int>  b, vector<int>  res, int line, int size);
		~Item();
		void setline(int line);
		void setSize(int n);
		vector<int>& getA();
		vector<int>& getB();
		vector<int>& getRES();
		int getSize();
		int getLINE();
	};
}



