#include <iostream>
#include <fstream>

using namespace std;



int main() {
    int IGaveUp[1000] = {0};
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int N; fin >> N;
    for(int i = 0; i < N; i++) {
        int x, y, z;
        fin >> x >> y >> z;
        for(int i = (x-1); i < y; i++)
            IGaveUp[i] += z;
    }
    int max = 0;
    for(int i = 0; i < 1000; i++) {
        if(IGaveUp[i] > max)
            max = IGaveUp[i];
    }
    // cout << max << endl;
    fout << max << endl;
}