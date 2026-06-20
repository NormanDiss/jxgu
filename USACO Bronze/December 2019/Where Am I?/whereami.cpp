#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    int N; string s;
    fin >> N >> s;
    //find largest shared sequence of S
    int largest = 0;
    for(int i = 0; i < (N - 1); i++) {
        int currentSeq = 0;
        for(int j = (i + 1); j < N; j++) {
            for(int k = i; k < N; k++) {
                int x = k + i;
                int y = k + j;
                if(s[x] == s[y]) {
                    currentSeq++;
                } else {
                    break;
                }
            }
        if(currentSeq > largest) {
            largest = currentSeq;
            cout << i << j << endl;
        }
        }

    }
    cout << largest << endl;
    return 0;
}