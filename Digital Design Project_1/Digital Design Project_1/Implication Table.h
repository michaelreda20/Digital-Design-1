#pragma once
#include <iostream>
#include"Minterm.h"
#include"Dont_care_terms.h"
#include <vector>
#include<map>


class implication_table 
{
   public:
    vector <Minterm> minterms;
    vector <Dont_care_terms> Dont_cares;
   implication_table(vector <Minterm> m, vector <Dont_care_terms> d );
   implication_table();
    map<int, vector<term>> curr;
    map<int, vector<term>> New;
    map<term, bool> visited;
    vector<term> PIs;
    void Calc();

};

