#include <iostream>
#include <string>
using namespace std;

/* Author: Ethan Freebersyser
 * Date: 8/21/2025
 * This is a improved solution to the kattis problem "lv-able", https://open.kattis.com/problems/lvable
 */

int main(){
	int numOfChars;
	cin >> numOfChars;

	int numOfsteps;
	if (numOfChars == 0) {
		cout << 2;
		return 0;
	}
	
	string s;
	cin >> s;

	if (s.find("lv") != string::npos) {
		cout << 0;
		return 0;
	}

	bool l = false, v = false;
	for (char c: s){
		if (c == 'l') l = true;
		if (c == 'v') v = true;
	}

	cout << ((l || v) ? 1 : 2);
	return 0;
}
