/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int N;
    fin >> N;
    vector<vector<int>> lines;
    for(int x = 1; x <= N; x++) {
        vector<int> toInput;
        for(int i = 0; i < x; i++) {
            int z;
            fin >> z;
            toInput.push_back(z);
        }
        lines.push_back(toInput);
    }
    fout << "NotSetYet" << endl;
    return 0;
    
}
