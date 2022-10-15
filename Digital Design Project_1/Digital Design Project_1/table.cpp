#include"table.h"

table::table() {
    cout << "hellor";
}
int table::zero() {
    return 0;
}
void table::Calculate() {

    for (int i = 0; i < minterms.size(); i++) {
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
                        
                        visited[curr[i][j].Binary_Representation] = true;
                     visited[curr[i + 1][k].Binary_Representation] = true;
             
                     term m = curr[i][j];
                     
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
               if(!inserted[curr[i][j].Binary_Representation])
                 PIs.push_back(curr[i][j]);
               inserted[curr[i][j].Binary_Representation] = true;
             
             }

         }
     }
     curr = New;
     


    }
}
