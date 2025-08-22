
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Author: Ethan Freebersyser
 * Date: 8/22/2025
 * This is a solution to the kattis problem "#include main.hpp", https://open.kattis.com/problems/includefile
 */

int main(){
        int numOfLines, rLimit; long long numOfErrors;
        cin >> numOfLines >> rLimit >> numOfErrors;
        
        string dead;
        getline (cin, dead);
        
        vector <string> lines;
        vector <string> finalLines; 
        lines.reserve(numOfLines);
        for (int i = 0; i < numOfLines; i++) {
                string temp1;
                string temp2;
                getline(cin, temp1);
                temp2 = temp1;
                lines.push_back(move(temp1));
                finalLines.push_back(move(temp2));
        }
        
        vector <long long> errorLoc(numOfErrors);
        for (int i = 0; i < numOfErrors; i++) cin >> errorLoc[i];
        
        for (int i = 0; i < rLimit; i++){
            int size =  finalLines.size();
            for (int j = 0; j < size; j++){
                if (finalLines.at(j) == "#include \"main.hpp\""){
                    for (int k = numOfLines - 1; k > 0 ; k--){
                        finalLines.insert(finalLines.begin() + j + 1, lines.at(k));
                    }
                }
            }
        }   
        
        for (int loc: errorLoc) cout << finalLines.at(loc - 1) << "\n";
        
        return 0;
}
