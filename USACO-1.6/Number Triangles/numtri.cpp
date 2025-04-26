/*
ID: ayushn.2
TASK: numtri
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>

using namespace std;

int checkTotal(vector<vector<int> > lines, int N, string z) {
    // cout << z << " | ";
    int currentPos = 0; // Current position
    int currentTotal = 0;
    for(int i = 0; i < N; i++) {
        vector<int> asdf = lines[i];
        // cout << " + " << asdf[currentPos];
        currentTotal += asdf[currentPos]; 
        int x = z.at(i);
        x -= 48;
        currentPos += x;
    }
    return currentTotal;
}
int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int N;
    fin >> N;
    vector<vector<int> > lines;
    for(int x = 1; x <= N; x++) {
        vector<int> toInput;
        for(int i = 0; i < x; i++) {
            int z;
            fin >> z;
            toInput.push_back(z);
        }
        lines.push_back(toInput);
    }
    // Now generate the desired binary numbers from 0 to 2^N - 1, and do operations on them.
    int n = pow(2, N) - 1;
    int currentMax = -100;

    queue<string> q;

    q.push("1");

    while(n--)
    {
        string s1 = q.front();
        q.pop();
        string z = s1; // Random variable to store data with to append 0's to the end.
        while(z.length() < N) {
            z += "0";
        }
        
        // Check path through Z with the vector
        int currentTotal = checkTotal(lines, N, z);
        // cout << " = " << currentTotal << endl;
        if(currentTotal > currentMax)
            currentMax = currentTotal;
        // Do z, but with a 0 at the front instead of a 1
        z.replace(0, 1, "0");
        currentTotal = checkTotal(lines, N, z);
        // cout << " = " << currentTotal << endl;
        if(currentTotal > currentMax)
            currentMax = currentTotal;
        string s2 = s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));

    }

    fout << currentMax << endl;
    return 0;

}
