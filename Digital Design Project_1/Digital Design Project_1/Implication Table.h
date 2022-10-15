#pragma once
#include <iostream>
#include"Minterm.h"
#include"Dont_care_terms.h"
#include "term.h"
#include <vector>
#include<map>

using namespace std;
class implication_table 
{
   public:
    vector <Minterm> minterms;
    vector <Dont_care_terms> Dont_cares;
    implication_table();
    void Calculate();
    map<int, vector<term>> curr;
    map<int, vector<term>> New;
    map<term, bool> visited;
    vector<term> PIs;
    int zero();

};

