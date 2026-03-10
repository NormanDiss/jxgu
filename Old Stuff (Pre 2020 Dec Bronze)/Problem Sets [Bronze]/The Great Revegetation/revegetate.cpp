#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    int M, N, maze[150][2];
    for(int i = 0; i < M; i++) {
        fin >> maze[i][0] >> maze[i][1];
    }
    string toTest[400];
    vector<string> correct;
    // generate array here


    for(int i = 0; i < (4*N); i++) {
        bool correct = true;
        for(int i = 0; i < M; i++) {
            if(toTest[i][maze[i][0]] == toTest[i][maze[i][1]]) {
                correct = false;
                break;
            }
        }
        if(correct) {
            
        }
    }
}