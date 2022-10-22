#include"Implication Table.h"

implication_table::implication_table() {
    cout << "hellor";
}
int implication_table::zero() {
    return 0;
}
void implication_table::Calculate(){
    /*
    for (int i = 0; i < minterms.size(); i++) {
        curr[minterms[i].ones].push_back(minterms[i]);
    }
    for (int i = 0; i < Dont_cares.size(); i++) {
        curr[Dont_cares[i].ones].push_back(Dont_cares[i]);
    }
    while(New.size()!=0){
       New.clear();

    int size = minterms[0].var_numbers;
    for(int i = 0; i < size; i++){
        for(int j = 0; j != curr[i].size(); j++){
            for(int k = 0; k != curr[i+1].size(); k++){
                if(curr[i][j].calc_distance(curr[i+1][k]).first==1){
                    visited[curr[i][j]] = true;
                    visited[curr[i+1][k]] = true;
                    term m = curr[i][j];
                    m.Binary_Representation[curr[i][j].calc_distance(curr[i+1][k]).second] ='_';
                    New[i].push_back(m);
                }
            }
        }
    }
     for(int i = 0; i < size; i++){
        for(int j = 0; j != curr[i].size(); j++){
            if(!visited[curr[i][j]]){
                PIs.push_back(curr[i][j]);
            }
        }
    }
    curr = New;
    }
 
   */
    
}
