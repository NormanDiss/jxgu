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

char s[20][20];

int main () {
    ifstream cin("where.in");
    int N; cin >> N;
    // Load into array
    FOR(i, N) {
        string sl;
        cin >> sl;
        FOR(j, N) {
            s[i][j] = sl[j];
        }
    }
    // FOR(i, N) {
    //     FOR(j, N) {
    //         cout << s[i][j] << endl;
    //     }
    // }

    // Select Points
    
    return 0;

}