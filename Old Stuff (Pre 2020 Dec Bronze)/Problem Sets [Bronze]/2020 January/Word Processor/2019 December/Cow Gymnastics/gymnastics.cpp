#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int check(int maze[10][20], int x, int y, int N, int K) {
  int firstChar, secondChar;
  for(int i = 0; i < N; i++) {
    if(maze[0][i] == x) {
      firstChar = x;
      secondChar= y;
    } else if(maze[0][i] == y) {
      firstChar = y;
      secondChar = x;
    }
  }
  for(int i = 1; i < K; i++) {
    // In here parse each one
    for(int j = 0; i < N; i++) {
      if(maze[i][j] == firstChar) {
         break;
      } else if(maze[i][j] == secondChar) {
        return 0;
      }
      
    }
  }
  return 1;
}


int main() {
  ifstream fin("gymnastics.in");
  ofstream fout("gymnastics.out");
  int K, N, maze[10][20], cnt = 0;
  fin >> K >> N;
  for(int i = 0; i < K; i++) {
    for(int j = 0; j < N; j++) {
      fin >> maze[i][j];
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
      if(check(maze, i, j, N, K) == 1)
        cnt++;
    }
  }

  fout << cnt << endl;
  cout << cnt << endl;

  return 0;
}
