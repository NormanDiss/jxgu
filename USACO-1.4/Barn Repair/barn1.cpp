/*
ID: ayushn.2
TASK: barn1
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
ofstream outputFile ("barn1.out");
    ifstream inputFile ("barn1.in");
    int m, c, s;
    inputFile >> m >> s >> c;
    vector<int> stallsOccupied;
    for(int i = 0; i < c; i++) {
        int z;
        inputFile >> z;
        stallsOccupied.push_back(z);
    }
    // Time for Initialization

    outputFile << "NotSetYet" << endl;
    return 0;
    
}