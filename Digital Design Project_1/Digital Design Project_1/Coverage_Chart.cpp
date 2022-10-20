#include "Coverage_Chart.h"

void Coverage_Chart::populate_EPIs()
{
    for (int i = 0; i < PIs.size(); ++i) {
        for (int j = 0; j < PIs[i].covered_minterms.size(); ++j) {
            chart[PIs[i].covered_minterms[j].Binary_Representation].push_back(PIs[i]);
        }
    }
    //Each prime implicants has minterms
    //I switch it to be that each minterm's binary representation vector contains prime implicants it is included in

    map<string, vector<term>>::iterator it;
    for (it = chart.begin(); it != chart.end(); ++it) {
        pair<string, vector<term>> pr = *it;
        if (pr.second.size() == 1 && !visited[pr.second[0].Binary_Representation]) {
            EPIs.push_back(pr.second[0]);
            visited[pr.second[0].Binary_Representation] = true;
            for (int i = 0; i < pr.second[0].covered_minterms.size(); ++i) {
                visited[pr.second[0].covered_minterms[i].Binary_Representation] = true;
            }
        }
    }

    for (int i = 0; i < PIs.size(); ++i) {
        if (!visited[PIs[i].Binary_Representation]) {
            for (int j = 0; j < PIs[i].covered_minterms.size(); ++j) {
                if (!visited[PIs[i].covered_minterms[j].Binary_Representation]) {
                    uncovered.push_back(PIs[i].covered_minterms[j]);
                    visited[PIs[i].covered_minterms[j].Binary_Representation] = true;
                }
            }
        }
    }
}
