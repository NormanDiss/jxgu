/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct cow {
    int s, t, b;
};

int main()
{   
    ofstream fout ("blist.out");
    ifstream fin ("blist.in");
    int N, topMilk = 0;
    fin >> N;
    vector<cow> maze;
    for(int i = 0; i < N; i++) {
        cow tooAdd;
        fin >> tooAdd.s >> tooAdd.t >> tooAdd.b;
        maze.push_back(tooAdd);
    }


    for(int i = 0; i < 1000; i++) {
        // Iterate through the vector to see if it should be added, and if so, add its amount to MilkAmount
        int currentMilk = 0;
        for(int j = 0; j < N; j++) {
            if(maze[j].s <= i && maze[j].t >= i) {
                currentMilk += maze[j].b;
            }
        }

        if(currentMilk > topMilk)
            topMilk = currentMilk;
    }


    cout << topMilk << endl;
    fout << "NotSetYet" << endl;
    return 0;
    
}