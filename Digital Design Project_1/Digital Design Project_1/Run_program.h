#pragma once
#include <iostream>
#include "Minterm.h"
#include "Dont_care_terms.h"
#include <vector>
#include"Implication Table.h"
using namespace std;
class Run_program
{
public:
	string input_file_path;
	vector<Minterm> Minterms;
	vector<Dont_care_terms> Dont_cares;
	Run_program(string file);
	void Run();
	void fillIn();
	implication_table ip;
	Run_program();
};

