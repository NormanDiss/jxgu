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
	int N, T;
	vector<int> maze;
	cin >> N >> T;
	maze.resize(N);
	for(int i = 0; i < N; i++) {
		cin >> maze[i];
	}
	// So basically, the algorithm is that the two pointers start out at the same place, and then the first one jumps as far as it can, then the second one moves up one, then the second moves up as far as it can and so on until it hits the end.
	return 0;
}

