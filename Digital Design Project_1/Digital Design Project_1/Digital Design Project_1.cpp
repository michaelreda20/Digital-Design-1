// Digital Design Project_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Run_program.h"

int main()
{
    string path ="input.txt";
    Run_program run;
    table t;

    run.input_file_path = path;
    run.Run();
    vector<term> printterm =run.PIs;
    vector<term>::iterator it = printterm.begin();
    cout << "Prime Implicants: \n";
    for (it; it!=printterm.end();it++)
    {
        term t = *it;
        cout << t.Var_Representation;
        cout << "\nMinterms: ";
        if (!t.covered_minterms.size()) cout << "X";
        for (int i = 0; i < t.covered_minterms.size(); ++i) {
            cout << t.covered_minterms[i].number << "  ";
        }
        cout << "\nDon't Cares: ";
        if (!t.covered_dont_cares.size()) cout << "X";
        for (int i = 0; i < t.covered_dont_cares.size(); ++i) {
            cout << t.covered_dont_cares[i].number << "  ";
        }
        cout << "\n\n";
    }

    cout << "\nEssential Prime Implicants: \n";
    for (int i = 0; i < run.EPIs.size(); ++i) {
        cout << run.EPIs[i].Var_Representation << endl;
    }

    cout << "\nUncovered Minterms: \n";
    for (int i = 0; i < run.uncovered.size(); ++i) {
        cout << run.uncovered[i].number << endl;
    }
}


