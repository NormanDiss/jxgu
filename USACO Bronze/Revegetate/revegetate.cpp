#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int colors[100], arr[150][2], N, M;

void colorItUp(int targetIndex, vector<vector<int> > plots) {
    int done[4];
    for(int i = 0; i < plots[targetIndex].size(); i++) {
        plots[targetIndex][i];
    } 
}

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    vector<vector<int> > maze; maze.resize(100);
    fin >> N >> M;
    for(int i = 0; i < N; i++) {
        fin >> arr[i][0] >> arr[i][1];
        maze[arr[i][0]].push_back(arr[i][1]);
    }
    // Now start linking through with a 


}