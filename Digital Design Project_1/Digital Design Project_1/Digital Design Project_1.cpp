// Digital Design Project_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "table.h"
#include "Run_program.h"

int main()
{
    string path ="input.txt";
    Run_program run;
    table t;

    run.input_file_path = path;
    run.Run();
    vector<term> printterm = run.PIs;
    vector<term>::iterator it = printterm.begin();
    cout << "Prime Implicants: \n";
    if (printterm.size() == 0)
        cout << "X\n";
    for (it; it!=printterm.end();it++)
    {
        term t = *it;
        cout << t.Var_Representation << "  " << t.Binary_Representation;
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
    if (run.EPIs.size() == 0)
        cout << "X\n";
    for (int i = 0; i < run.EPIs.size(); ++i) {
        cout << run.EPIs[i].Var_Representation << "  " << run.EPIs[i].Binary_Representation << endl;
    }

    cout << "\nUncovered Minterms: \n";
    if (run.uncovered.size() == 0)
        cout << "X\n";
    for (int i = 0; i < run.uncovered.size(); ++i) {
        cout << run.uncovered[i].number << endl;
    }
    
}



