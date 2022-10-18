#include "Coverage_Chart.h"

void Coverage_Chart::populate_EPIs()
{
    for (int i = 0; i < PIs.size(); ++i) {
        for (int j = 0; j < PIs[i].covered_terms.size(); ++j) {
            chart[PIs[i].covered_terms[j].Binary_Representation].push_back(PIs[i]);
        }
    }

    map<string, vector<term>>::iterator it;
    for (it = chart.begin(); it != chart.end(); ++it) {
        pair<string, vector<term>> pr = *it;
        if (pr.second.size() == 1 && visited[pr.second[0].Binary_Representation] == false) {
            EPIs.push_back(pr.second[0]);
            visited[pr.second[0].Binary_Representation] = true;
        }
    }

}
