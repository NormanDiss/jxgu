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

int n, m, roads[10000][2];
bool visited[10000] = {0};
vi current;

void dfs(int x) {
    if(visited[roads[x][0]]) return;
    visited[roads[x][0]] = true;
    current.pb(x);
    for(auto u: roads[x]) {
        dfs(u);
    }
}

int main () {
    ifstream cin("input.in");
    cin >> n >> m;
    // Check for connected roads.
    
    FOR(i, n) {
        int a, b; cin >> a >> b;
    }
    dfs(1);
    for(auto u: current) {
        cout << u << endl;
    }
    return 0;

}