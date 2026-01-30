#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int check(int x[7][2], int arr[8],int  n) {
    // Check if Verifies Conditions
	for(int i = 0; i < n; i++) {
		// check all of them
		int base = x[i][0];
		int additive = x[i][1];
		for(int j = 0; j < 8; j++) {
			if(arr[j] == base) {
				if(arr[j - 1] == additive || arr[j + 1] == additive){
					// Nothing
				} else {
					return 0;
				}
			}
		}
		
	}
    return 1; // 0 or 1 for false/true
}
int convert(string x) {
	if(x == "Beatrice") {
		return 1;
	} 
	if(x == "Belinda") {
		return 2;
	}
	if (x == "Bella") {
		return 3;
	}
	if (x == "Blue" ) {
		return 4;
	} 
	if (x == "Bessie") {
		return 5;
	}
	if (x == "Betsy") {
		return 6;
	}
	if (x == "Buttercup") {
		return 7;
	}
	if (x == "Sue") {
		return 8;
	}
	return 0;
}

int main() {
  // 1 -> Beatrice
  // 2 -> Belinda
  // 3 -> Bella
  // 4 -> Blue
  // 5 -> Bessie
  // 6 -> Betsy
  // 7 -> Buttercup
  // 8 -> Sue
  ofstream fout("lineup.out");
  ifstream fin("lineup.in");
  int N;
  int maze[7][2];
  fin >> N;
  for(int i = 0; i < 6*N; i++) {
      string s;
      fin >> s;
      if(i % 6 == 0) {
          maze[(i)/6][0] = convert(s); 
      } else if(i % 6 == 5) {
          maze[(i - 5)/6][1] = convert(s);
      }
  }
  // Brute Force!
	int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(a) / sizeof(a[0]);
	// All Permutations
	do {
		if(check(maze, a, N))
			cout << maze << endl;
	} while (next_permutation(a, a + n));
	
	

	
  for(int i = 0; i < N; i++){
	  cout << maze[i][0] << maze[i][1] << endl;
  }   
  return 0;
  
  }
