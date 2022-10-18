#include"table.h"

table::table() {
    cout << "hellor";
}
int table::zero() {
    return 0;
}

void table::Calculate() {

    for (int i = 0; i < minterms.size(); i++) {
        term x = minterms[i];
        minterms[i].covered_terms.push_back(x); // x = minterms[i]
        curr[minterms[i].ones].push_back(minterms[i]);
    }
    for (int i = 0; i < Dont_cares.size(); i++) {
        curr[Dont_cares[i].ones].push_back(Dont_cares[i]);
    }
    bool first = true;
    while (New.size() != 0|| first) {
        first = false;
        New.clear();

        int size = minterms[0].var_numbers;
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j != curr[i].size(); j++) {
                for (int k = 0; k != curr[i + 1].size(); k++) {
                    if (curr[i][j].calc_distance(curr[i + 1][k]).first == 1) {
                        
                     visited[curr[i][j].Binary_Representation] = true;  //vctor 1 of covered items (m)
                     visited[curr[i + 1][k].Binary_Representation] = true; //vctor 2 of covered items
             
                     term m = curr[i][j];
                     m.covered_terms.insert(m.covered_terms.end(), curr[i + 1][k].covered_terms.begin(), curr[i + 1][k].covered_terms.end());

                     m.Binary_Representation[curr[i][j].calc_distance(curr[i+1][k]).second] ='-';
                     New[i].push_back(m);
                     cout << curr[i][j].Binary_Representation << " " << curr[i+1][k].Binary_Representation << " " << m.Binary_Representation << endl;
                 }
             }
         }
     }
        cout << endl;
        
      for(int i = 0; i < size; i++){
         for(int j = 0; j != curr[i].size(); j++){
             if(!visited[curr[i][j].Binary_Representation]){
                 if (!inserted[curr[i][j].Binary_Representation]) {
                     PIs.push_back(curr[i][j]);
                     cout << curr[i][j].covered_terms.size() << endl;
                 }
               inserted[curr[i][j].Binary_Representation] = true;
             
             }

         }
     }
     curr = New;
     


    }
}
