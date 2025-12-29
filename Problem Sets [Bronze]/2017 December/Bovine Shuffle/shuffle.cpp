/*
ID: ayushn.2
TASK: shuffle
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


vector<int> deShuffle(vector<int> x, int N, int shuffle[]) {
    vector<int> newS;
    newS.resize(N);
    for(int i = 0; i < N; i++) {
        newS[i] = x[shuffle[i]];
    }
    return newS;
}

int main()
{
    ofstream fout ("suffle.out");
    ifstream fin ("shuffle.in");
    int N, shuffle[100];
    vector<int> s1, s2, s3, idStack;
    fin >> N;
    idStack.resize(N);


    for(int i = 0; i < N; i++) {
        fin >> shuffle[i];
    }

    for(int i = 0; i < N; i++) {
        fin >> idStack[i];
    }

    s1 = deShuffle(idStack, N, shuffle);
    s2 = deShuffle(s1, N, shuffle);
    s3 = deShuffle(s2, N, shuffle);

    for(int i = 0; i < N; i++) {
        cout << s3[i] << endl;
    }


    fout << "NotSetYet" << endl;
    return 0;
    
}