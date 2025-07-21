/*
ID: ayushn.2
TASK: subset
LANG: C++11
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int N;
    fin >> N;
    int sum = (N * (N+1))/2;
    cout << sum << endl;
    fout << "NotSetYet" << endl;
    return 0;
    
}