#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Author: Ethan Freebersyser
 * Date: 8/20/2025
 * This is a solution to the kattis problem "lv-able", https://open.kattis.com/problems/lvable
 */

int main(){
        int numOfChars;
        cin >> numOfChars;
        
        string s;
        cin >> s;
        
        vector<int> lloc(numOfChars);
        fill(lloc.begin(), lloc.end(), -1);
        vector<int> vloc(numOfChars);
        fill(vloc.begin(), vloc.end(), -1);
        
        for  (int i = 0; i < numOfChars; i ++){
                if (s[i] == 'l') lloc.push_back(i);
                if (s[i] == 'v') vloc.push_back(i);
        }
        
        int numOfSteps= 3;
        int tempSteps = 3;
        
        for (int l: lloc){
                for (int v: vloc){

                        if (l + v == -2) tempSteps = 2;
                        
                        if ((l == -1 && v > -1) || (l > -1 && v == -1)) tempSteps = 1;
                        if (v < l || l + 1 < v) tempSteps = 1;
                        
                        if (v - l == 1) tempSteps = 0;
                        
                        if(tempSteps < numOfSteps) numOfSteps = tempSteps;
                }
        }
        cout << numOfSteps;
}
