#include <iostream>
#include <string>
using namespace std;

/* Author: Ethan Freebersyser
 * Date: 8/20/2025
 * This is a solution to the kattis problem "#include main.hpp", https://open.kattis.com/problems/includefile
 */

int main(){
	int numOfLines;
	cin >> numOfLines;

	int rLimit;
	cin >> rLimit;

	int numOfErrors;
	cin >> numOfErrors;

	string mainS[numOfLines];
	for (int i = 0; i < numOfLines; i++){
		cin >> mainS[i];
	}
	
	int32_t errorLoc[numOfErrors];
        for (int i = 0; i < numOfErrors; i++){
                cin >> errorLoc[i];
        }

        for (int i = 0; i < numOfErrors; i++){
                cout << mainS[errorLoc[i] % numOfLines];
        }
	
	return 0;
}
