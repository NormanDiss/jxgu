#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool possible(int N, int M, int C, int X, int maze[]) {
    // Maze should be ordered, X is the value to check (max time)

    // This function tries to minimize the amount of buses used, goes through allocating a new bus once each distance measurement is maximized or capacity is maximized, and then checks whether there are enough buses
    
    int moveForeward = X, capacity = C, currentPos = 0, busUsed = 0, currentBusEnd = -1, currentBusCapacity = 0;

    while(currentPos < N) {
        if(maze[currentPos] > currentBusEnd) {
            currentBusEnd = maze[currentPos] + moveForeward;
            currentBusCapacity = 0;
            busUsed++;
        }
        if(currentBusCapacity == capacity) {
            currentBusEnd = maze[currentPos] + moveForeward;
            currentBusCapacity = 0;
            busUsed++;  
        }
        currentBusCapacity++;
        currentPos++;
    }
    if(busUsed > M) {
        return false;
    } else {
        return true;
    }
}

int main() {
    ifstream fin("convention.in");
    ofstream fout("convention.out");
    int N, M, C;
    fin >> N >> M >> C; 
    int maze[N];
    for(int i = 0; i < N; i++) {
        fin >> maze[i];
    }
    int y = sizeof(maze) / sizeof(maze[0]);
    sort(maze, maze+y);
    
    // Binary Search on Answer
    int checkNum;
    int maxNum = maze[N];
    int lowNum = 0;
    vector<int> values;
    while(values[values.size()] != values[values.size() - 1]) {
        checkNum = ceil((float(maxNum) + float(lowNum)/2.0));
        if(possible(N, M, C, checkNum, maze)) {
            maxNum = checkNum;
            values.push_back(checkNum);
        } else {
            lowNum = checkNum;
        }
        continue;
    }
    cout << checkNum << endl;

    return 0;
}