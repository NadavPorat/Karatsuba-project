#pragma once

namespace krt
{
	class Calc
	{
	private:
	public:
	    // Func that checks if two input vectors have same size.
		int lengthController(vector<int>& Vx, vector<int>& Vy);
		// Func that suntracts second input vector from the first input vector and returns the result vector after sabtraction.
		vector<int> subtract(vector<int> v1, vector<int> v2);
		// Fun that sums up two input vectors and returns the result vector.
		vector<int> add(vector<int> v1, vector<int> v2);
		// Func that deletes leading Zeros in a given input vector.
		void fitRes(vector<int>& res);

		// Karatsuba Recursive Func - Multiplies between two (very large) input numbers given as vectors .
		vector<int> multiplyRec(vector<int> Vx, vector<int> Vy);

		// Karatsuba (Not Recursive - Iterative) Func - Multiplies between two (very large) input numbers given as vectors .
		void multiplyIter(vector<int>& X, vector<int>& Y, vector<int>& res);
	};
}