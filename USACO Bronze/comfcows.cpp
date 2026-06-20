#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair
#define pb push_back

#define FAR(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, a) for (int i=0; i<a; i++)

#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

struct cow {
    int x, y;
    vector<vector<int> > adj;
};

int main () {
    ifstream cin("input.in");
    int N; cin >> N;
    cow maze[2000][2000];
    int mazeBool[2000][2000] = {0};
    vector<cow> originals;
    FOR(i, N) {
        cow temp; cin >> temp.x >> temp.y;
        maze[temp.x+500][temp.y+500] = temp;
        mazeBool[temp.x+500][temp.y+500] = 1;
        originals.push_back(temp);
    }  
    cout << maze[10][1].x << endl;
    

    return 0;
}
