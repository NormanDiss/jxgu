#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int check(string x) {
    // Check if Verifies Conditions
    return 0; // 0 or 1 for false/true
}

int main() {
  // A -> Beatrice
  // B -> Belinda
  // C -> Bella
  // D -> Blue
  // E -> Bessie
  // F -> Betsy
  // G -> Buttercup
  // H -> Sue
  ofstream fout("lineup.out");
  ifstream fin("lineup.in");
  int N;
  string maze[7][2];
  fin >> N;
  for(int i = 0; i < 6*N; i++) {
      string s;
      fin >> s;
      cout << s << endl;
      if(i % 6 == 0) {
          maze[(i)/6][0]; // TODO CONVERT TO ABCDEFGH
      } else if(i % 6 == 5) {
          maze[(i + 1)/6][1]; // TODO CONVERT TO ABCDEFGH
      }
  }
  // Brute Force!
  string a = "ABCDEFGH";
  // TODO ADD PERMUTATION OF STRING a HERE!!!!!!!!!!!!!
  return 0;
  }
