#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/* Author: Ethan Freebersyser
 * Date: 8/20/2025
 * This Program is a solution to the Kattis problem "Virtual Friends", https://open.kattis.com/problems/virtualfriends
 */

struct UnionFind{
	vector<int> root, sizeOfTree;

	int add() {
		int id = (int)root.size();
		root.push_back(id);
		sizeOfTree.push_back(1);
		return id;
	}

	int findLeader(int x){
		if (root[x] = x) return x;
		//Compression!
		return root[x] = findLeader(root[x]);
	}

	int unite(int a, int b){
		a = findLeader(a);
		b = findLeader(b);
		if (a == b) return sizeOfTree[a];
		if (sizeOfTree[a] < sizeOfTree[b]) swap(a,b);
		root[b] = a;
		sizeOfTree[a] += sizeOfTree[b];
		return sizeOfTree[a];
	}
};


int main(){
	int numOfTestCases;
	int numOfFriendships;
	vector<string> friends;
	
	cin >> numOfTestCases;
	if (!numOfTestCases) return 0;
	for (int i = 0; i < numOfTestCases; i++){
		cin >> numOfFriendships;
	

		UnionFind uf;
		uf.root.reserve(2 * numOfFriendships);
		uf.sizeOfTree.reserve(2 * numOfFriendships);

		unordered_map<string, int> id;
		id.reserve(2 * numOfFriendships * 2);
	
		for (int j = 0; j < numOfFriendships; j++){
			string a,b;
			cin >> a >> b;
	
			if (!id.count(a)) id[a] = uf.add();
			if (!id.count(b)) id[b] = uf.add();

			int endingSize = uf.unite(id[a], id[b]);
			cout << endingSize << "\n";
		}
	}
}
