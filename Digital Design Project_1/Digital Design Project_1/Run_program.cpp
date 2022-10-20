#include "Run_program.h"

/*Run_program::Run_program(string in) {
	input_file_path = in;
}*/
int Run_program::Run() {
	fillIn();
	if (!Minterms.size() == 0) {
		table t;
		t.minterms = Minterms;
		t.Dont_cares = Dont_cares;
		t.Calculate();
		PIs = t.PIs;
		Coverage_Chart chart;
		chart.PIs = PIs;
		chart.populate_EPIs();
		EPIs = chart.EPIs;
		uncovered = chart.uncovered;
	}
	
	return 0;
}

/*Run_program::Run_program()
{

}*/

void Run_program::fillIn() {

	ifstream input;
	input.open(input_file_path);
	int line_count = 0;
	string line;
	int var_numbers= 0;
	while (input)
	{
		
		getline(input, line);
		if (line_count == 0) {
			var_numbers = stoi(line);
			if (var_numbers == 0) {
				errors[-1] = "Error: \n There are no variables! \n Please enter at least one variable";
				break;
			}
		}
		else if (line_count == 1) {
			string temp = "";
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ',') {
					Minterm m(stoi(temp), var_numbers);
					//cout <<m.number<<" "<<m.var_numbers << endl;
					if (m.number > (pow(2, var_numbers) - 1)) {
						errors[0] += (" " + to_string(m.number));
					}
					else {
						Minterms.push_back(m);
					
					}
					temp = "";
				}
				else {
					temp += line[i];
				}
			}
			if (temp != "") {
				Minterm m(stoi(temp), var_numbers);
				//cout << m.number << " " << m.var_numbers << endl;
				if (m.number > (pow(2, var_numbers) - 1)) {
					errors[0] += (" " + to_string(m.number));
				}
				else {
					Minterms.push_back(m);

				}
				temp = "";
			}
		}
		else {
			string temp = "";
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ',') {
					Dont_care_terms d(stoi(temp), var_numbers);
					if (d.number > (pow(2, var_numbers) - 1)) {
						errors[1] += (" " + to_string(d.number));
					}
					else {
						Dont_cares.push_back(d);
						
					}
					temp = "";
				}
				else {
					temp += line[i];
				}
			}
			if (temp != "") {
				Dont_care_terms d(stoi(temp), var_numbers);
				if (d.number > (pow(2, var_numbers) - 1)) {
					errors[1] += (" " + to_string(d.number));
				}
				else {
					Dont_cares.push_back(d);

				}
				temp = "";
			}
			break;
		}

		line_count++;
		

	}
}