/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct wedge {
    int start;
    int end;
};

struct wheel {
    int speed;
    int wedgeNum;
    vector<wedge> wedges;
};

int main()
{
    ofstream fout ("spin.out");
    ifstream fin ("spin.in");
    vector<wheel> smh;
    for(int i = 0; i < 5; i++) {
        wheel s;
        fin >> s.speed >> s.wedgeNum;
        for(int j = 0; j < s.wedgeNum; j++) {
            wedge x;
            fin >> x.start >> x.end;
            s.wedges.push_back(x);
        }
        smh.push_back(s);
    }
    // Everything gathered

    int a1[359]

    fout << "NotSetYet" << endl;
    return 0;
    
}