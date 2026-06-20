#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FAR(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, a) for (int i=0; i<a; i++)

#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

int N, M, C;
int maze[100000];

int solve(int maze[], int BS) {
    // Assign cows to busses, max waiting time.
    int currentWait = maze[0];
    int bussesUsed = 1;
    int currentCap = 1;
    FAR(i, 1, N) {
        if((maze[i] - currentWait) >= BS ) {
            currentWait = maze[i];
            bussesUsed++;
            currentCap = 1;
        } else if( currentCap > C) {
            currentWait = maze[i];
            bussesUsed++;
            currentCap = 1;
        } else {
            currentCap++;
        }
    }

    if(bussesUsed > M) {
        return 1;
    } else {
        return 0;
    }
}

int binarySolve(int low, int high, function<bool(int)> solve) {
    for(--low; low < high; ) {
        int mid = low+(high-low + 1)/2;
        if(solve(mid)) low = mid;
        else high = mid-1;
    }
    return low;
}


int main () {
    ifstream cin("convention.in");
    cin >> M >> N >> C;
    FOR(i, N) {
        cin >> maze[i];
    }
    int n = sizeof(maze)/sizeof(maze[0]);
    sort(maze, maze+n);
    
    // BSearch
    cout << binarySolve(0, 120938, solve) << endl;
    
    return 0;
}
