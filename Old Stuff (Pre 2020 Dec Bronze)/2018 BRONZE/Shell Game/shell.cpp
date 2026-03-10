#include <iostream>
#include <fstream>

using namespace std;
int swapped[100][3], N;

void swapit(int abs, int maze[3], int swap[100][3]) {
    if(abs == N)
        return;
    int newMaze[3];
    // check all three for swap
    if(swap[abs][0] == 1) {
        if(swap[abs][1] == 2) {
            newMaze[0] = maze[1];
            newMaze[1] = maze[0];
            newMaze[2] = maze[2];
        }
        if(swap[abs][1] == 3) {
            newMaze[0] = maze[2];
            newMaze[2] = maze[0];
            newMaze[1] = maze[1];
        }
    }
    if(swap[abs][0] == 2) {
        if(swap[abs][1] == 3) {
            newMaze[1] = maze[2];
            newMaze[2] = maze[1];
            newMaze[0] = maze[0];
        }
        if(swap[abs][1] == 1) {
            newMaze[0] = maze[1];
            newMaze[1] = maze[0];
            newMaze[2] = maze[2];
        }
    }
    if(swap[abs][0] == 3) {
        if(swap[abs][1] == 2) {
            newMaze[1] = maze[2];
            newMaze[2] = maze[1];
            newMaze[0] = maze[0];
        }
        if(swap[abs][1] == 3) {
            newMaze[0] = maze[2];
            newMaze[2] = maze[0];
            newMaze[1] = maze[1];
        }
    }
    // cout << newMaze[0] << newMaze[1] << newMaze[2] << endl;
    swapped[abs][0] = newMaze[0];
    swapped[abs][1] = newMaze[1];
    swapped[abs][2] = newMaze[2];
    swapit(abs + 1, newMaze, swap);

}

int main() {
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int swp[100][3];
    fin >> N;
    for(int i = 0; i < N; i++)
        fin >> swp[i][0] >> swp[i][1] >> swp[i][2];
    int x[3] = {1, 2, 3};
    int count[3] = {0};
    swapit(0, x, swp);

    for(int i = 0; i < N; i++)
        count[swapped[i][swp[i][2]]]++;
    int max = 0;
    for(int i = 0; i < 3; i++) {
        if(count[i] > max)
            max = count[i];
    }
    
    cout << max << endl;
    
    for(int i = 0; i < N; i++) {
        cout << swapped[i][0] << swapped[i][1] << swapped[i][2] << endl;
    }
}