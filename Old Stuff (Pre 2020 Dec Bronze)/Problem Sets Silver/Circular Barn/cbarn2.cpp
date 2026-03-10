#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int N, maze[1000];
	ifstream fin("cbarn.in");
	ofstream fout("cbarn.out");
	vector<int> values;
	fin >> N; 
	for(int i = 0; i < N; i++) fin >> maze[i];
	for(int i = 0; i < N; i++) {
		int arr[1000] = { 0 }, energy = 0;
		map<int, int> places; // for storing the initial location of each cow j - this value = how many doors
		if(maze[i] == 0) { continue; }
		for(int j = i; j < (N + i); j++) {
			// Start by adding anything to the map
			for(int i = 0; i < maze[j % N]; i++) { places.insert(pair<int, int>((j % N), 1)); }
			// Now add anything from the maze into the thingy
			// Energy hit
			arr[j % N] = 1;
			int traveled = places.begin()->first;
			energy += (j - traveled) * (j - traveled);
			places.erase(places.begin(), places.begin()); // Delete first value from map
		}
		values.push_back(energy);
	}
	sort(values.begin(), values.end());
	fout << values[values.size()] << endl;
	return 0;
}
