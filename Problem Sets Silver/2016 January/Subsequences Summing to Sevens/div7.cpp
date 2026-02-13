#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
	// Starting off with Prefix Sums
	ifstream fin("div7.in");
	ofstream fout("div7.out");
	int N, maze[50000], modV = 0;
	fin >> N;
	// Get the Modulus Prefix Sums
	for(int i = 0; i < N; i++) {
		int temp;
		fin >> temp;
		modV += temp;
		modV = modV % 7;
		maze[i] = modV;
	}
	// Now mod prefix sums, we just have to find equal ones.
	
	for (int i = 0; i < N; i++) {

	}
	
	return 0;
};
