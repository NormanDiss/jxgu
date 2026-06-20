#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#define ll long long


using namespace std;


int main () {
	ifstream fin("word.in");
	ofstream fout("word.out");
	int N, K;
	fin >> N >> K;
	vector<string> x; x.resize(N);
	for(int i = 0; i < N; i++)
		fin >> x[i]; 

	vector<string> maze;
	string currentS = x[0];
	for(int i = 1; i < N; i++) {
		// Gather Size of x[i]
		if((currentS.size() + x[i].size()) > K) {
			maze.push_back(currentS);
			currentS = x[i];
		} else {
			currentS += " ";
			currentS += x[i];
		}
	}
	maze.push_back(currentS);

	for(int i = 0; i < maze.size(); i++) {
		cout << maze[i] << endl;
	}
	

	return 0;
}

