#include <iostream>
#include <fstream>
#include <utility>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

struct cartesian {
  int x, y;
};

bool cmp(const cartesian& x, const cartesian& y) {
  return x.y < y.y;
}

int main() {
  ifstream fin("mountain.in");
  int N;
  vector<cartesian> maze;
  fin >> N;
  maze.resize(N);

  for(int i = 0; i < N; i++) {
    fin >> maze[N].x >> maze[N].y;
  }

  sort(begin(maze), end(maze), cmp);


  return 0;
}
