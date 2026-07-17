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

int arr[100000] = {0};


int main () {
    ifstream cin("measurement.in");
    int N, G;
    vector<pair<int, pair<int, int> > > logs;
    cin >> N >> G;
    logs.resize(N);    
    FOR(i, N) {
        cin >> logs[i].first >> logs[i].second.first >> logs[i].second.second;
    }

    sort(logs.begin(), logs.end());
    int changes = 0;
    int currentMax = -1;
    vector<int> topId;
    FOR(i, N) {
        arr[logs[i].second.first] += logs[i].second.second;
        if (arr[logs[i].second.first] > currentMax) {
            changes += 1;
            currentMax = arr[logs[i].second.first];
            topId.clear();
            topId.push_back(logs[i].second.first);
        }
    }
    
    return 0;

}