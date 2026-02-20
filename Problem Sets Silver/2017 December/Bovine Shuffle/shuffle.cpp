#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int N; fin >> N;
    vector<int> x; x.resize(N);
    for(int i = 0; i < N; i++)
        fin >> x[i];
    
    // Now Find First Empties
    
}