#include "Global.h"

namespace krt
{
	// Func that checks if two input vectors have same size.
	int Calc::lengthController(vector<int>& num1, vector<int>& num2)
	{
		int len1 = (int)num1.size();
		int len2 = (int)num2.size();

		if (len1 < len2)
		{
			for (int i = 0; i < len2 - len1; i++)
				num1.insert(num1.begin(), 0);
			return len2;
		}

		if (len1 > len2)
		{
			for (int i = 0; i < len1 - len2; i++)
				num2.insert(num2.begin(), 0);
			return len1;
		}
		return len1;
	}
	// Func that suntracts second input vector from the first input vector and returns the result vector after sabtraction.
	vector<int> Calc::subtract(vector<int> v1, vector<int> v2)
	{
		int len = lengthController(v1, v2);
		vector<int> res;
		int diff;

		for (int i1 = len - 1; i1 >= 0; i1--)
		{
			diff = v1[i1] - v2[i1];
			if (diff >= 0)
			{
				res.insert(res.begin(), diff);
			}
			else
			{
				int i2 = i1 - 1;
				while (i2 >= 0)
				{
					v1[i2] = (v1[i2] - 1) % 10;
					if (v1[i2] != 9)
						break;
					else
						i2--;
				}
				res.insert(res.begin(), diff + 10);
			}
		}
		Calc::fitRes(res);
		return res;
	}

	// Fun that sums up two input vectors and returns the result vector.
	vector<int> Calc::add(vector<int> v1, vector<int> v2)
	{
		int size = lengthController(v1, v2);
		int carry = 0;
		int sum;
		vector<int> res;

		for (int i = size - 1; i >= 0; i--)
		{
			sum = v1[i] + v2[i] + carry;
			carry = sum / 10;
			res.insert(res.begin(), (sum % 10));
		}
		if (carry)
		{
			res.insert(res.begin(), carry);
		}
		Calc::fitRes(res);
		return res;
	}
	// Func that deletes leading Zeros in a given input vector.
	void Calc::fitRes(vector<int>& res)
	{
		int i = 0;
		while (res[i] == 0 && i < res.size() - 1)
			i++;
		res.erase(res.begin(), res.begin() + i);
	}
	// Karatsuba Recursive Func - Multiplies between two (very large) input numbers given as vectors 
	vector<int> Calc::multiplyRec(vector<int> Vx, vector<int> Vy)
	{
		int len = lengthController(Vx, Vy), i = 0;
		vector<int> res;
		if (len == 1)
		{
			int result = Vx[0] * Vy[0];
			if (result == 0)
			{
				res.push_back(0);
				return res;
			}

			if ((result >= 10))
			{
				res.push_back((result / 10));
				res.push_back((result % 10));
				return res;
				while (res[i] == 0)
				{
					i++;
				}
				res.erase(res.begin(), res.begin() + i);
				return res;
			}
			else
			{
				res.push_back((result));
				while (res[i] == 0 && i < res.size() - 1)
					i++;
				res.erase(res.begin(), res.begin() + i);
				return res;
			}
		}
		else
		{
			vector<int>::iterator x_aPart = Vx.begin(), y_cPart = Vy.begin();
			vector<int>::iterator x_bPart = Vx.begin() + (len / 2), y_dPart = Vy.begin() + (len / 2);
			vector<int> a(Vx.begin(), x_bPart);
			vector<int> b(x_bPart, Vx.end());
			vector<int> c(Vy.begin(), y_dPart);
			vector<int> d(y_dPart, Vy.end());

			vector<int> res1 = multiplyRec(a, c);
			vector<int> res2 = multiplyRec(b, d);
			vector<int> res3 = multiplyRec(add(a, b), add(c, d));
			vector<int> res4 = subtract(subtract(res3, res2), res1);

			for (int i = 0; i < 2 * (len - (len / 2)); i++)
				res1.push_back(0);

			for (int i = 0; i < (len - (len / 2)); i++)
				res4.push_back(0);
			res = add(add(res1, res2), res4);
			fitRes(res);
			return (res);
		}
	}
	// Karatsuba (Not Recursive - Iterative) Func - Multiplies between two (very large) input numbers given as vectors.
	void Calc::multiplyIter(vector<int>& X, vector<int>& Y, vector<int>& res)
	{
		Stack s;
		Item cur(X, Y, res, START, lengthController(X, Y));
		int falga = 0;
		do
		{
			if (falga) /// if falga ='true'  we need to save "cur" and get the last node in the stack.
			{
				Item last = s.pop();
				s.push(cur);
				cur = last;
				falga = 0;
			}

			if (cur.getLINE() == START)
			{
				if (cur.getSize() <= 1) // base case: A and B are vectors of 1 digit.
				{
					if (cur.getSize() > 0)
					{
						int val = cur.getA().back() * cur.getB().back();
						if (val > 9) // if the val is bigger then 9 we need to save two digits.
						{
							cur.getRES().push_back(val / 10);
							cur.getRES().push_back(val % 10);
						}
						else // save value
							cur.getRES().insert(cur.getRES().begin(), val);
						falga = 1; // returnFromRecursion
					}
				}
				else
				{
					if (cur.getSize() % 2 == 1) //if cur hold odd vector we need to add zero. 
					{
						cur.getA().insert(cur.getA().begin(), 0);
						cur.getB().insert(cur.getB().begin(), 0);
						cur.setSize(cur.getSize() + 1);
					}
					cur.setline(AFTER_FIRST);
					s.push(cur);
					cur.setSize(cur.getSize() / 2);
					//Keep the value of a for future use.
					vector<int>a(cur.getA().begin(), cur.getA().begin() + cur.getSize());
					//Keep the value of c for future use.
					vector<int>c(cur.getB().begin(), cur.getB().begin() + cur.getSize());
					cur = Item(a, c, vector<int>(), START, cur.getSize());
				}
			}
			else if (cur.getLINE() == AFTER_FIRST)
			{
				cur.setline(AFTER_SECOND);
				s.push(cur);
				cur.setSize(cur.getSize() / 2);
				//Keep the value of b for future use.
				vector<int>b(cur.getA().begin() + cur.getSize(), cur.getA().end());
				//Keep the value of d for future use.
				vector<int>d(cur.getB().begin() + cur.getSize(), cur.getB().end());
				cur = Item(b, d, vector<int>(), START, cur.getSize());
			}
			else if (cur.getLINE() == AFTER_SECOND)
			{
				Item bd = s.pop();
				Item ac = s.pop();
				bd.setline(AFTER_THIRD);
				s.push(cur);
				s.push(ac);
				s.push(bd);
				vector<int>sumAB = add(ac.getA(), bd.getA());
				vector<int>sumCD = add(ac.getB(), bd.getB());
				cur = Item(sumAB, sumCD, vector<int>(), START, cur.getSize());
				int size = lengthController(cur.getA(), cur.getB());
				cur.setSize(size);
			}
			else if (cur.getLINE() == AFTER_THIRD)
			{//Initialize values for use in Karatusuba calculation.
				vector<int> bd = cur.getRES();
				vector<int> temp = s.pop().getRES();
				vector<int> ac = s.pop().getRES();
				vector<int> sumACBD = add(ac, bd);
				vector<int> sub = subtract(temp, sumACBD);
				cur = s.pop();
				//Some Zeros shifting
				for (int i = 0; i < 2 * (cur.getSize() - (cur.getSize() / 2)); i++)
					ac.push_back(0);
				for (int i = 0; i < (cur.getSize() - (cur.getSize() / 2)); i++)
					sub.push_back(0);
				cur.getRES() = add(add(ac, sub), bd);
				falga = 1;
			}
		} while (!s.isEmpty());
		res = cur.getRES(); //Get the result
	}
}