#include "Run_program.h"
#include <fstream>
Run_program::Run_program(string in) {
	input_file_path = in;
	for (int i = 0; i < in.length(); i++) {
		if (input_file_path[i] == '\'') {
			input_file_path[i] = '/';
		}
	}
}
void Run_program::Run() {
	fillIn();
	ip.minterms=Minterms;
	ip.Dont_cares=Dont_cares;
	ip.Calc();
}

Run_program::Run_program()
{
// hiiiiiii
}

void Run_program::fillIn() {
	ifstream input;
	input.open(input_file_path);
	int line_count = 0;
	string line;
	int var_numbers= 0;
	//cout << "here" << endl;
	while (input)
	{
		
		getline(input, line);
		if (line_count == 0) {
			var_numbers = stoi(line);

		}
		else if (line_count == 1) {
			string temp = "";
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ',') {
					Minterm m(stoi(temp), var_numbers);
					Minterms.push_back(m);
					temp = "";
				}
				else {
					temp += line[i];
				}
			}
			Minterm m(stoi(temp), var_numbers);
			Minterms.push_back(m);
			temp = "";
		}
		else {
			string temp = "";
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ',') {
					Dont_care_terms d(stoi(temp), var_numbers);
					Dont_cares.push_back(d);
					temp = "";
				}
				else {
					temp += line[i];
				}
			}
			Dont_care_terms d(stoi(temp), var_numbers);
			Dont_cares.push_back(d);
			temp = "";
			break;
		}

		line_count++;
		

	}
}