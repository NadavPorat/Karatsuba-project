/**************************************************************************************
Project by:
1. Nadav Porat

 **************************************************************************************/
#include "Global.h"
using namespace krt;

int main()
{
	bool inputTest = true;
	string sx, sy, n;
	vector<int> Vx;
	vector<int> Vy;
	vector<int> res1;
	vector<int> res2;
	vector<int> res3;
	Calc v;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Get Inputs (n , x , y)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cin >> n;
	cin >> sx;
	cin >> sy;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Check Inputs (n , x , y)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	inputTest = CheckInput(sx, sy, n);
	if (!inputTest)
	{
		cout << "Wrong output" << endl;
		exit(1);
	}

	convert(sx, sy, Vx, Vy); //Convert the strings to vectors before the use of Karatsuba funcs.

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Time Calculations and Func use~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//F1 time calc + use:
	auto start1 = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false); 	// unsync the I/O of C and C++.

	cout << "Long multiplication: x * y = ";
	Longmultiply(Vx, Vy, res1);
	v.fitRes(res1);
	for (int j = 0; j < res1.size(); j++)
	{
		cout << res1[j];
	}
	cout << endl;

	auto end1 = chrono::high_resolution_clock::now();
	double time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();	// Calculating total time taken by the program.
	time_taken1 *= 1e-9;

	//F2 time calc + use:
	auto start2 = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);	// unsync the I/O of C and C++.

	res2 = v.multiplyRec(Vx, Vy);
	cout << "Karatsuba (recursive): x * y = ";
	for (int j = 0; j < res2.size(); j++)
	{
		cout << res2[j];
	}
	cout << endl;

	auto end2 = chrono::high_resolution_clock::now();
	double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();	// Calculating total time taken by the program.
	time_taken2 *= 1e-9;

	//F3 time calc + use:
	auto start3 = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);	// unsync the I/O of C and C++.

	v.multiplyIter(Vx, Vy, res3);// Here you put the name of the function you wish to measure
	v.fitRes(res3);
	cout << "Karatsuba (iterative): x * y = ";
	for (int j = 0; j < res3.size(); j++)
	{
		cout << res3[j];
	}
	cout << endl;

	auto end3 = chrono::high_resolution_clock::now();
	double time_taken3 = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();	// Calculating total time taken by the program.
	time_taken3 *= 1e-9;

	//Create a txt file named: "Measure.txt" and write the times there.
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <Longmultiply> is : " << fixed << time_taken1 << setprecision(9);
	myfile << " sec" << endl;
	myfile << "Time taken by function <multiplyRec> is : " << fixed << time_taken2 << setprecision(9);
	myfile << " sec" << endl;
	myfile << "Time taken by function <multiplyNotRec> is : " << fixed << time_taken3 << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~End of Time Calculations and Func use~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	return 0;
}