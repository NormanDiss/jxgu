#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct cow {
    int arrive, spent, seniority;
};



int main() {
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");
    int N; fin >> N;
    vector<cow> maze;
    for(int i = 0; i < N; i++) {
        fin >> maze[i].arrive >> maze[i].spent;
        maze[i].seniority = i;
    }
    

}