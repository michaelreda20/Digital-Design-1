#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "term.h"
using namespace std;


class Coverage_Chart
{
public:
	vector<term> PIs;
	vector<term> EPIs;
	map<string, vector<term>> chart;   
	vector<term> minterms;
	map<string, bool> visited;

	void populate_EPIs();
};

