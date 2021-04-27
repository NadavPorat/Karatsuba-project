#include "Global.h"
namespace krt {
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~convert string to vector~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void convert(string& SX, string& SY, vector<int>& x, vector<int>& y)
	{
		int i = 0;
		while (SX[i])
		{
			x.push_back(SX[i] - '0');
			y.push_back(SY[i] - '0');
			i++;
		}
		return;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Check if The Input is valid~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool CheckInput(string  x, string  y, string n)
	{
		//Check if the n paramater starts with '0' Or not number
		if (n.at(0) < '1' || n.at(0) > '9')
		{
			return false;
		}
		for (int i = 1; i < n.length(); i++)
		{
			if (n[i] < '0' || n[i] > '9') /// n[1]=k < '0'
			{
				return false;
			}
		}

		//Check if the length of x or y isn't equal to the length of n 
		if (x.length() != stoi(n) || y.length() != stoi(n))
		{
			return false;
		}

		//Check that all Digits of x,y,n are valid (between 0-9)
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] < '0' || x[i] >'9')
			{
				return false;
			}
			if (y[i] < '0' || y[i] > '9')
			{
				return false;
			}
		}
		return true;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Long multiplication function:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void  Longmultiply(vector<int>& x, vector<int>& y, vector<int>& res)////string num1, string num2
	{
		int len1 = (int)x.size();
		int len2 = (int)y.size();
		if (len1 == 0 || len2 == 0)
		{
			res = { 0 };
		}
		// will keep the result number in vector
		// in reverse order
		int totalLen = len1 + len2;
		vector<int> result(totalLen, 0);
		// Below two indexes are used to find positions
		// in result.
		int i_n1 = 0;
		int i_n2 = 0;
		int carry = 0;
		int n1;
		// Go from right to left in num1
		for (int i = len1 - 1; i >= 0; i--)
		{
			carry = 0;
			n1 = x[i];
			// To shift position to left after every
			// multiplication of a digit in num2
			i_n2 = 0;
			// Go from right to left in num2
			for (int j = len2 - 1; j >= 0; j--)
			{
				// Take current digit of second number
				int n2 = y[j];
				// Multiply with current digit of first number
				// and add result to previously stored result
				// at current position.
				int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
				// Carry for next iteration
				carry = sum / 10;
				// Store result
				result[i_n1 + i_n2] = sum % 10;
				i_n2++;
			}
			// store carry in next cell
			if (carry > 0)
				result[i_n1 + i_n2] += carry;
			// To shift position to left after every
			// multiplication of a digit in num1.
			i_n1++;
		}
		// ignore '0's from the right
		int i = (int)(result.size() - 1);
		while (i >= 0 && result[i] == 0)
			i--;
		// If all were '0's - means either both or
		// one of num1 or num2 were '0'
		if (i == -1)
		{
			res = { 0 };
		}
		vector<int> s;
		res.resize(result.size(), 0);
		int size = result.size();
		for (int i = 0; i < size; i++)
		{
			res[i] = result.back();
			result.pop_back(); //Delete the stack when it is not needed anymore.

		}
	}
}