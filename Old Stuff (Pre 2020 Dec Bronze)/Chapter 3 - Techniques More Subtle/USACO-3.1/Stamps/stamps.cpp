/*
ID: ayushn.2
TASK: stamps
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");
    int N, K;
    int val[201];
    int dp[2000000];
    fin >> K >> N;
    for(int i = 0; i < N; i++)
        fin >> val[i];
    
    for(int i = 0; i < (K * 10000); i++) {

        dp[i] = K * 10000; // Max N

        for(int j = 0; j < N; j++) {
            
        }
    }
    
    
    fout << "NotSetYet" << endl;
    return 0;
    
}