#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;
#include"Item.h"
#include"Karatsuba.h"
#include"Stack.h"
#define START 0
#define AFTER_FIRST  1
#define AFTER_SECOND  2
#define AFTER_THIRD 3

namespace krt
{
// Func that gets as input 3 input numbers given as strings (x , y are the numbers and n is their length).
// The func makes some input tests to check if the input is valid and returns 'true' if so, else it returns 'false'.
bool CheckInput(string  x, string  y, string n);

// Func that gets as input two vector refernces and two string references and converts the strings into vectors.
void convert(string& SX, string& SY, vector<int>& x, vector<int>& y);

// Func that gets as input two vectors and another 'result' vector , the func makes "long multiplication" between them and saves the result in the given 'result' vector.
void Longmultiply(vector<int>& x, vector<int>& y, vector<int>& res);
}

