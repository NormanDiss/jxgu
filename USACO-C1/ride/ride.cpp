/*
ID: ayush.n2
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ofstream outputFile ("ride.out");
    ifstream inputFile ("ride.in");
    string line1, line2;
    inputFile >> line1 >> line2;
    int l1 = 1;
    int l2 = 1;
    int cnt = 0;

    for (char c : line1) {
        int nc = c;
        nc -=  64;
        l1 *= nc;
    }
        
    for (char c : line2) {
        int nc = c;
        nc -=  64;
        l2 *= nc;
    }

    if ((l2 % 47) == (l1 % 47)) { // Works
        cout << "GO" << endl;
        outputFile << "GO" << endl;
        return 0;
    } else {
        cout << "STAY" << endl;
        outputFile << "STAY" << endl;
        return 0;
    }

    return 0;
    
}