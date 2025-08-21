#include <iostream>
#include <string>

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

	int numOfSteps;
	
	int l = -1;
	int v = -1;
	for  (int i = 0; i < numOfChars; i ++){
		if (s[i] == 'l') l = i;
		if (s[i] == 'v') v = i;
	}

	if (l + v == 0) numOfSteps = 2;
	if (l + 1 == v) numOfSteps = 0;

	if (l == -1 || v == -1) numOfSteps = 1;
	if (v < l || l + 1 < v) numOfSteps = 1;

	cout << numOfSteps;
}
