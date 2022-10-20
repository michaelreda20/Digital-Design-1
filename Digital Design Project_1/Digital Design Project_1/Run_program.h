#pragma once
#include <fstream>
#include "table.h"
#include "Coverage_Chart.h"

using namespace std;
class Run_program
{
public:
	string input_file_path;
	vector<Minterm> Minterms;
	vector<Dont_care_terms> Dont_cares;
	int Run();
	void fillIn();
	vector<term> PIs;
	vector<term> EPIs;
	vector<term> uncovered;
//	Run_program();
};

