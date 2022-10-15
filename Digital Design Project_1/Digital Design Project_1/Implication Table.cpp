#include"Implication Table.h"
#include<iterator>
implication_table::implication_table(vector <Minterm> m, vector <Dont_care_terms> d )
{
 minterms = m;
 Dont_cares = d;
for(int i = 0; i < minterms.size(); i++){
    curr[minterms[i].ones].push_back(minterms[i]);
}
for(int i = 0; i < Dont_cares.size(); i++){
    curr[Dont_cares[i].ones].push_back(Dont_cares[i]);
}

}

implication_table::implication_table()
{
    
}
void implication_table::Calc(){
    
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
   

    
}
