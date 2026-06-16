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

int main () {
    ifstream cin("input.in");
    int N, Q, curr = 0;
    vi a;
    vi b;
    cin >> N >> Q;
    a.resize(N);
    b.push_back(0);
    FOR(i, N) {
        cin >> a[i];
        curr += a[i];
        b.push_back(curr);
    }
    FOR(i, Q) {
        int x, y;
        cin >> x >> y;
        cout << b[y] - b[x] << endl;
    }
    // FOR(i, N) {
    //     cout << a[i] << ":";
    // }
    // cout << endl;
    // FOR(i, N) {
    //     cout << b[i] << ":";
    // }
    cout << endl;
    cout << endl;
    return 0;

}
