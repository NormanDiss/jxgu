#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define FOR(i, a) for (int i=0; i<a; i++)
#define endl "\n"

int N, K, L;

void debug(vi toPrint) {
    FOR(i, toPrint.size()) {
        cout << toPrint[i] << " ";
    }
    cout << endl;
}

bool f(vi maze, int C, int N) {

    // cout << C << endl;
    int remain = K * L;
    int depth = K;
    for(int i = C - 1; i >= 0; i--) {
        int currentdepth = C - maze[i];
        // cout << currentdepth << ":" << remain << ":" << maze[i] << endl;
        if(currentdepth > 0) {
            if(currentdepth > K) {
                // cout << "F" << endl;
                return false;
            }
            if(remain < 0) {
                // cout << "F" << endl;
                return false;
            }
            remain -= currentdepth;
        }
    }
    // cout << "C" << endl;
    return true;
}

int main () {
    // ifstream cin("input.in");
    cin >> N >> K >> L;
    vi maze; maze.resize(N);
    FOR(i, N) { cin >> maze[i]; }
    sort(maze.begin(), maze.end(), greater<int>());
    // debug(maze);
    int lo = 1, hi = N;

	for (int dif = (hi-(--lo)); dif; dif /= 2)
		while (lo+dif <= hi && f(maze, lo+dif, N)) lo += dif;
    cout << lo << endl;


    return 0;
}
