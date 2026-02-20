#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

int main () {
	ifstream fin("diamond.in");
	ofstream fout("diamond.out");
	int N, K;
	fin >> N >> K;
	vector<int> maze;
	maze.resize(N);
	for(int i = 0; i < N; i++) fin >> maze[i];
	sort(maze.begin(), maze.end());
	// Now do two pointers once, and then again, afterwards, this should run in N(log(N)) + 2N
	int j = 0;
	for(int i = 0; i < N; i++) {
		//i is the first pointer, j is the second pointer
		
	}
	return 0;
}

