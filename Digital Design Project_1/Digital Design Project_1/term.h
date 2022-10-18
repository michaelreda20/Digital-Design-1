#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma once
class term
{
public:
	int var_numbers = 0;
	long number = 0;
	string Var_Representation;
	string Binary_Representation;
	vector<term> covered_terms;
	void Initialize();
	int ones= 0;
	void count_ones();
	pair<int, int> calc_distance(term another);

};
