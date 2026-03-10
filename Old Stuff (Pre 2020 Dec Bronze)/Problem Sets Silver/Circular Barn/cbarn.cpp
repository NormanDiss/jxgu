#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	ifstream fin("cbarn.in");
	ofstream fout("cbarn.out");
	int N, maze[1000];
	vector<int> values;
	fin >> N;
	for(int i = 0; i < N; i++) fin >> maze[i];
	for(int i = 0; i < N; i++) {
		// Simulate
		int arr[1000] = {0}, energy = 0; // Current Room Occupation, Cost
		for(int j = i; j < (i+N); j++) {
			int pos = (j % N);
			// Now place all the current ones
			for(int k = 0; k < maze[pos]; k++) {
				// Now place each of these
				int cnt = 0;
				while(arr[cnt] != 0) { cnt++; }
				arr[cnt] = 1;
				energy += (cnt * cnt);
			}
		}
		values.push_back(energy);
	}
	sort(values.begin(), values.end(), greater<int>());
	for(int i = 0; i < N; i++) cout << values[i] << endl; // Debug

	fout << values[0] << endl;
	return 0;
}
