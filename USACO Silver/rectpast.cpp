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

int N; 
vector<pi> pairs; 
int cows[2500][2500] = {0};
int pfxs[2500][2500];
int pfx[2500][2500];

bool secsort(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }

void debugPairs() {
    for(int i = 0; i < N; i++) {
        cout << pairs[i].fi << ":" << pairs[i].se << endl;
    }
    cout << endl;
}

void debugCows() {
    FOR(i, N) {
        FOR(j, N) {
            cout << cows[i][j] << " ";
        }
        cout << endl;
    }
}
int main () {
    ifstream cin("input.in");
    cin >> N;
    pairs.resize(N);
    FOR(i, N) {
        cin >> pairs[i].fi >> pairs[i].se;
    }

    sort(pairs.begin(), pairs.end());
    int currentStep = pairs[0].fi, currentValue = 0;
    FOR(i, N) {
        if(pairs[i].fi != currentStep) {
            currentValue++;
            currentStep = pairs[i].fi;
        }
        pairs[i].fi = currentValue;
    }

    sort(pairs.begin(), pairs.end(), secsort);
    currentStep = pairs[0].se; currentValue = 0;
    FOR(i, N) {
        if(pairs[i].se != currentStep) {
            currentValue++;
            currentStep = pairs[i].se;
        }
        pairs[i].se = currentValue;
        cows[pairs[i].fi][pairs[i].se] = 1;
    }
    
    debugCows();
    cout << endl;
    
    // 2D prefix Sums
    int current = 0;
    FOR(i, N) {
        current = 0;
        FOR(j, N) {
            current += cows[i][j];
            pfxs[i][j] = current;
        }
    }

    FOR(i, N) {
        FOR(j, N) {
            cout << pfxs[i][j] << " ";
        }
        cout << endl;
    }

    current = 0;
    FOR(i, N) {
        current = 0;
        FOR(j, N) {
            current += pfxs[j][i];
            pfx[j][i] = current;
        }
    }

    cout << endl;
    FOR(i, N) {
        FOR(j, N) {
            cout << pfx[i][j] << " ";
        }
        cout << endl;
    }


    
    return 0;
}
