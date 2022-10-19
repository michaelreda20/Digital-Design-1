#include "Coverage_Chart.h"

void Coverage_Chart::populate_EPIs()
{
    for (int i = 0; i < PIs.size(); ++i) {
        for (int j = 0; j < PIs[i].covered_minterms.size(); ++j) {
            chart[PIs[i].covered_minterms[j].Binary_Representation].push_back(PIs[i]);
        }
    }

    map<string, vector<term>>::iterator it;
    for (it = chart.begin(); it != chart.end(); ++it) {

        pair<string, vector<term>> pr = *it;
        if (pr.second.size() == 1 && !visited[pr.second[0].Binary_Representation]) {
            EPIs.push_back(pr.second[0]);
            visited[pr.second[0].Binary_Representation] = true;
        }
        else {
            for (int j = 0; j < pr.second.size(); ++j) {
                if (!visited[pr.second[j].Binary_Representation]) {
                    uncovered.push_back(pr.second[j]);
                    visited[pr.second[j].Binary_Representation] = true;
                }
            }
        }

    }
}
