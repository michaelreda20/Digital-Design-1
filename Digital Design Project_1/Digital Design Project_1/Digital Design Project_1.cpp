

#include <iostream>
#include "table.h"
#include "Run_program.h"
#include <time.h>
#include <chrono> 
using namespace std;
int main()
{
    cout << "Welcome to Quine McCLuskey Algorithm Solver: " << endl;
    cout << "How many boolean functions you want to test? " << endl;
    int test_cases = 0;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        
        auto start = std::chrono::high_resolution_clock::now();
        cout << "Test case #" << i+1 << endl;
        cout << "Please enter the path of your file: " << endl;

        string path;
        cin >> path;
        Run_program run;
        //table t;
        run.input_file_path = path;
        run.Run();
        // cout << run.Minterms.size() << endl;
        if (run.errors[-1] != "") {
            cout << run.errors[-1] << endl;
        }
        else {
            if (run.errors[0] != "") {
                cout << "Error:" << endl;
                cout << "Please note that the following minterms require more variables than the number of variables you entered: " << run.errors[0] << endl;
            }
            if (run.errors[1] != "") {
                cout << "Error:" << endl;
                cout << "Please note that the following Don't care terms require more variables than the number of variables you entered: " << run.errors[1] << endl;
            }
            vector<term> printterm = run.PIs;
            vector<term>::iterator it = printterm.begin();
            cout << "Prime Implicants: \n";
            if (printterm.size() == 0)
                cout << "X\n";
            for (it; it != printterm.end(); it++)
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

            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
           
                std::cout << "It took " << elapsed.count() << " s to finish this function\n";
           
            
            cout << "-------------------------------------------------------------------" << endl;
        }

    }
    system("pause");
}



