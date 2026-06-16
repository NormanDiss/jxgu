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
    ifstream cin("maxcross.in");
    ofstream cout("maxcross.out");
    int N, K, B; cin >> N >> K >> B;
    int arr[100000] = {0};
    FOR(i, B) {
        int temp; cin >> temp;
        arr[temp] = 1;
    }
    // pref sum
    int pref[100000], curr = 0;
    FOR(i, N) {
        curr += arr[i];
        pref[i] = curr;
    }
    // FOR(i, N) {
    //     cout << arr[i] << ":" << pref[i] << endl;
    // }
    int min = 1000000000;
    FOR(i, (N-K)) {
        if((pref[i+K] - pref[i]) < min) {
            min = (pref[i+K] - pref[i]);
        }
    }
    cout << min << endl;
    return 0;

}