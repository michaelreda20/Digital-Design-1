#pragma once
#include "Minterm.h"
#include "Dont_care_terms.h"

using namespace std;
class table
{
public:
    vector <Minterm> minterms;
    vector <Dont_care_terms> Dont_cares;
    table();
    void Calculate();
    map<int, vector<term>> curr;
    map<int, vector<term>> New;
    map<string, bool> visited;
    vector<term> PIs;
};

