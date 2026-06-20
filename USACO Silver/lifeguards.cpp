#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
int N;

int main() {
  ifstream fin("lifeguards.in");
  fin >> N;
  vector<pair<int,int> > maze;
  for(int i  = 0; i < N; i++) {
    int x, y;
    fin >> x >> y;
    maze.push_back( make_pair(x, y));
  }

  sort(maze.begin(), maze.end());
  // Strategy, is too maintain a vector that has the time and ending
  // then go through and toggle each person on and off

  for(int i = 0; i < N; i++) {
    // cout << maze[i].first << ":" << maze[i].second << endl;

  }




  return 0;
}