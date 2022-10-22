#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

using namespace std;
#pragma once
class term
{
public:
	int var_numbers = 0;
	long number = 0;
	string Var_Representation;
	string Binary_Representation;
	vector<term> covered_minterms;
	vector<term> covered_dont_cares;
	int ones = 0;

	void Initialize();
	void boolean_expression();
	void count_ones();
	pair<int, int> calc_distance(term const& another);
	term operator +(term const& another);
};
