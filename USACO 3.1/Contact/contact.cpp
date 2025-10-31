/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct num {
    string part;
    int freq;
};


int main()
{
    ofstream fout ("X.out");
    ifstream fin ("X.in");
    int A, B, N;
    fin >> A >> B >> N;
    string s = "";
    while(fin) {
        string x;
        fin >> x;
        s += x;
    }
    // Method -> just add everything to a list, order that list and BOOM done.
    cout << s.length() << endl;
    for(int i = 0; i < s.length(); i++)
    
    fout << "NotSetYet" << endl;
    return 0;
    
}