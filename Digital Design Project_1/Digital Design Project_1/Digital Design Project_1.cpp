// Digital Design Project_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "table.h"
#include "Run_program.h"
using namespace std;
int main()
{
    string path ="input.txt";
   Run_program run;
    table t;
    cout << t.zero();

 run.input_file_path = path;
 run.Run();
 cout << endl;
    vector<term> printterm =run.PIs;
    //cout << printterm.size();
    vector<term>::iterator it = printterm.begin();
    for (it; it!=printterm.end();it++)
    {
        term t = *it;
        cout << t.Binary_Representation << endl;
        for (int i = 0; i < t.covered_terms.size(); ++i) {
            cout << t.covered_terms[i].Binary_Representation << "  ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < run.EPIs.size(); ++i) {
        cout << run.EPIs[i].Binary_Representation << endl;
    }
    
    
}


