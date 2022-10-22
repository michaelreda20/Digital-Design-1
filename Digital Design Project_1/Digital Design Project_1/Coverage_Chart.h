#pragma once
#include "term.h"
using namespace std;


class Coverage_Chart
{
public:
	vector<term> PIs;
	vector<term> EPIs;
	vector<term> uncovered;
	map<string, vector<term>> chart;   
	map<string, bool> visited;

	void populate_EPIs();
};

