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
    ifstream fin("homework.in");
    ofstream fout("homework.out");
    int N; fin >> N;
    vi input(N+1);
    vi prefix(N+1);
    vi toSub(N+1);
    vector<vector<int> > sorted(N+1);
    int prefixValue = 0;
    FOR(i, N) {
        fin >> input[i];
        sorted[i].push_back(input[i]);
        sorted[i].push_back(i);
        prefixValue += input[i];
        prefix[i] = prefixValue;
    }

    sort(sorted.begin(), sorted.end());
    int persistentValue = 0;
    FOR(i, sorted.size()) {
        while(persistentValue < N) {
            if(sorted[persistentValue][1] < i) {
                toSub[i] = sorted[persistentValue][0];
                break;
            } else {
                persistentValue++;
            }
        }

        
        // cout << sorted[i][0] << " " << sorted[i][1] << endl;
    }

    FOR(i, toSub.size()) {
        cout << toSub[i] << endl;
    }
    
    
    return 0;
}
