#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int N, K;
    fin >> N >> K;
    vector<int> ordered; ordered.resize(N);
    for(int i = 0; i < N; i++) {fin >> ordered[i];}
    sort(ordered.begin(), ordered.end());
    int cMax = 0, cNum = 1;
    for(int i = 0; i < N - 1; i++) {
        if((ordered[i + 1] - ordered[i]) > K) {
            if(cMax > cNum) {cMax = cNum;}
            cNum = 1;
        } else {
            cNum++;
        }
    }
    cout << cNum << endl;

    return 0;
}