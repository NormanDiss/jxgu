#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

bool testSeq(int N, int start, int maze[]) {
    int temp[N + 1];
    set<int> checkDupe;
    checkDupe.insert(start);
    temp[0] = start;
    for(int i = 0; i < N; i++) {
       temp[i + 1] = maze[i] - temp[i]; 
       checkDupe.insert(maze[i] - temp[i]);
    }
    // Now check for dupes
    // Size of Array
    int len = sizeof(temp)/sizeof(temp[0]);
    if(checkDupe.size() != len) {
        return false;
    }
    for(int i = 0; i < N; i++) {
        if(temp[i] <= 0 ) {
            return false;
        }
    }
    for(int i  = 0; i < N; i++) {
        cout << temp[i] << ":";
    }
    cout << endl;
    return true;
}

int main() {
    ifstream fin("photoshoot.in");
    ofstream fout("photoshoot.out");
    int N, maze[1000]; 
    fin >> N;
    for(int i = 0; i < N; i++) {
        fin >> maze[i];
    }
    // guess and then move through
    for(int i = 0; i < N; i++) {
        if(testSeq(N, i, maze)) {
            cout << i << endl;
            fout << i << endl;
            return 0;
        }
    }
}