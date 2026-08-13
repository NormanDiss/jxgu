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
    ifstream cin("hps.in");
    int N;
    cin >> N;
    cout << N << endl;
    int pSum[100000], hSum[100000], sSum[100000], h = 0, p = 0, s = 0;
    FOR(i, N) {
        char ss; cin >> ss;
        if(ss == 'P') { p++; }
        else if(ss == 'H') { h++; }
        else { s++; }
        pSum[i] = p;
        hSum[i] = h;
        sSum[i] = s;
    }
    // int maxGamesWon = 0;
    FOR(i, N) {
        cout << pSum[i] << ":" << hSum[i] << ":" << sSum[i] << endl;
    }
    return 0;
}
