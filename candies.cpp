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
    int T; cin >> T;
    FOR(i, T) {
        // each test case
        int N, Q; cin >> N >> Q;
        int arr[100000], pre[100000];
        pre[0] = 0;
        int sweet = 0;
        int curr = 0;
        FOR(j, N) {
            cin >> arr[j];
            curr += j;
            
        }
    }
    return 0;
}
