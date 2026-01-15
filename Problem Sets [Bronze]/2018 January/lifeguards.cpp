/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
struct intPair {
    int start, end;
};

int reMap(int x, vector<intPair> maze) {
    maze.erase(maze.begin() + x);
    for(int i = 0; i < maze.size(); i++) {
        for(int j = maze[i].start; j <= maze[i].end; j++) {
            
        }
    }
    
}

int main()
{
    ofstream fout ("lifeguards.out");
    ifstream fin ("lifeguards.in");
    int N;
    fin >> N;
    vector<intPair> maze;

    for(int i = 0; i < N; i++) {
        intPair x;
        fin >> x.start >> x.end;
        maze.push_back(x);
        
    }
    // Brute Force

    for(int i = 0; i < N; i++) {


    }

    fout << "NotSetYet" << endl;
    return 0;
    
}