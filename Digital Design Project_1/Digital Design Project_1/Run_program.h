#pragma once
#include <iostream>
#include "Minterm.h"
#include "Dont_care_terms.h"
#include "table.h"
#include "Coverage_Chart.h"
#include <vector>


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

//	Run_program();
};

