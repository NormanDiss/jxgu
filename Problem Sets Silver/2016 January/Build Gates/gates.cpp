#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct position {
	int x, y;
};

bool compareInt(position x1, position x2) {
	if(x1.x == x2.x) {
		return x1.y < x2.y;
	} else {
		return x1.x < x2.x;
	}
}

int main() {
	ifstream fin("gates.in");
	ofstream fout("gates.out");
	int N, pos[2] = {0, 0}; 
	position maze[1000];
	string nodes;
	fin >> N >> nodes;
	for(int i = 0; i < N; i++) {
		char x = nodes[i];
		if(x == 'N')
			pos[1]++;
		else if(x == 'S')
			pos[1]--;
		else if(x == 'E')
			pos[0]++;
		else if(x == 'W')
			pos[0]--;
		maze[i].x = pos[0];
		maze[i].y = pos[1];
	}
	int n = sizeof(maze) / sizeof(maze[0]);
	for(int i = 0; i < N; i++) {
		cout << "(" << maze[i].x << "," << maze[i].y << "), ";
	}
	cout << endl;

	return 0;
}
