#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int N, M, limits[100][0], cnt = 0, maxAbove = 0;
    fin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x, y;
        fin >> x >> y;
        for(int i = cnt; i < (cnt + x); i++) {
            limits[i][0] = y;
        }
        cnt = (cnt + x);
    }
    cnt = 0;
        for(int i = 0; i < N; i++) {
        int x, y;
        fin >> x >> y;
        for(int i = cnt; i < (cnt + x); i++) {
            limits[i][1] = y;
        }
        cnt = (cnt + x);
    }
    // Now just compare arrays
    for(int i = 0; i < 100; i++) {
        if((limits[i][1] - limits[i][0]) > maxAbove) {

            maxAbove = (limits[i][1] - limits[i][0]);
        }
    }

    cout << maxAbove << endl;
    fout << maxAbove << endl;

    return 0;
}