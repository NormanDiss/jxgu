/*
 ID: ayushn.2
 LANG: C++11
 TASK: nocows
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define trace(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
typedef unsigned long long ull;
const int MOD = 9901;

ull dp[250][150];

int main() {

#ifndef STDIN
    freopen("nocows.out", "w", stdout);
    freopen("nocows.in", "r", stdin);
#endif

    int N, K;
    cin >> N >> K;

    // pre-calculate the values (bottom up)
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            if(i == 1) dp[i][j] = 1;
            else {
                for(int l=1; l <= i-2; l++)
                    dp[i][j] += dp[l][j-1] * dp[i-l-1][j-1];
                    dp[i][j] %= MOD;
            }
        }
    }

    // we need to find two trees
    // tree(N, K) = the one that we intended to find
    // tree(N, K-1) = result one level lower than K

    // - the subtraction of tree(N, K-1) is because there's non intended solutions
    //   on the tree(N,K) results.
    // - because we applies multiplication on result in `tree` function whenever `n=1`,
    //   we might include the non-intended solutions as well for level K-1

    cout << ((dp[N][K]-dp[N][K-1]+MOD) % MOD) << endl;

    return 0;
}