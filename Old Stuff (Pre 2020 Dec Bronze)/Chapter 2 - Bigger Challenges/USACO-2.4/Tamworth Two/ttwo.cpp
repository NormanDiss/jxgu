/*
ID: ayushn.2
TASK: ttwo
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> newDirection(vector<vector<char> > maze, vector<int> pos, int dir) {
    cout << pos[0] << ":" << pos[1] << endl;

    vector<int> toReturn;
    vector<int> newPosition;
    newPosition.push_back(pos[0]);
    newPosition.push_back(pos[1]);
    bool newDir = false;
    if(dir == 0) {
        newPosition[0]++;
    }
    if(dir == 1) {
        newPosition[1]++;
    }
    if(dir == 2) {
        newPosition[0]--;
    }
    if(dir == 3) {
        newPosition[1]--;
    }
    if(newPosition[0] == -1 || newPosition[0] == 10) {
        newDir = true;
    } else if(newPosition[1] == -1 || newPosition[1] == 10) {
        newDir = true;
    } else if(maze[newPosition[0]][newPosition[1]] == '*') {
        newDir = true;
    }


    if(newDir) {
        toReturn.push_back(pos[0]);
        toReturn.push_back(pos[1]);
        int x = dir++;
        int y = x % 4;
        toReturn.push_back(y);
    } else {
        toReturn.push_back(newPosition[0]);
        toReturn.push_back(newPosition[1]);
        toReturn.push_back(dir);
        
    }
    return toReturn;

}

int main()
{
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
    vector<vector<char> > maze;
    vector<int> fj;
    vector<int> tc;
    for(int i = 0; i < 10; i++) {
        vector<char> toMaze;
        toMaze.resize(10);
        for(int j = 0; j < 10; j++) {
            fin >> toMaze[j];
            if(toMaze[j] == 'F') {
                fj.push_back(i);
                fj.push_back(j);
            }
            if(toMaze[j] == 'C') {
                tc.push_back(i);
                tc.push_back(j);
            }
        }
        maze.push_back(toMaze);
    }
    int fjDir = 0;
    int cDir = 0; // 0: N, 1: E, 2: S, 3: W, and then it rotates!

    vector<int> currentC;
    currentC.push_back(tc[0]);
    currentC.push_back(tc[1]);
    vector<int> currentF;
    currentF.push_back(fj[0]);
    currentF.push_back(fj[1]);
    
    int cnt = 1;

    cout << "FINISHED INIT" << endl;

    while(cnt < 160000) {
        cout << cnt << endl;
        vector<int> burnerC = newDirection(maze, currentC, cDir);
        currentC[0] = burnerC[0];
        currentC[1] = burnerC[1];
        cDir = burnerC[2];
        vector<int> burnerF = newDirection(maze, currentF, fjDir);
        currentF[0] = burnerF[0];
        currentF[1] = burnerF[1];
        fjDir = burnerF[2];

        if(currentC == currentF) {
            cout << cnt << endl;
            return 0;
        }
        cnt++;
    }
    cout << "0" << endl;

    return 0;
    
}