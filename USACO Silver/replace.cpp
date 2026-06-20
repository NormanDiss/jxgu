#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define F0R(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, a) for (int i=0; i<a; i++)

#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

int main () {
    ifstream fin("replace.in");
    int n, q, k; fin >> n >> q >> k;
    vi maze(n+2), diff(n+2), pref(n+2);
    maze[0] = 0;
    fin >> maze[1];
    FOR(i, n) {
        int temp; fin >> temp;
        maze[i+2] = temp;
        diff[i] = 1;
    }
    
    return 0;
}
