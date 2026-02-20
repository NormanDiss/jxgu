#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    int B[4], S[4], G[4], P[4];
    fin >> B[0] >> B[1] >> S[0] >> S[1] >> G[0] >> G[1] >> P[0] >> P[1];
    B[2] = B[0];
    S[2] = S[0];
    G[2] = G[0];
    P[2] = P[0];

    // cout << S[2] << endl << G[2] << endl << P[2] << endl << endl;

    // Now start platinum downtrend (move golds to plat)
    G[2] -= (P[1] - P[0]); // Count the number of new platinums and subtract from golds
    P[3] = (P[1] - P[0]);
    P[2] += (P[1] - P[0]);

    // cout << S[2] << endl << G[2] << endl << P[2] << endl << endl;

    S[2] -= (G[1] - G[2]); // Count full delta of golds, subtract from silver
    G[3] =  (G[1] - G[2]);
    G[2] +=  (G[1] - G[2]);

    // cout << S[2] << endl << G[2] << endl << P[2] << endl << endl;

    B[2] -= (S[1] - S[2]); // Count full silvers, subtract from bronze (no need to calc new bronzes, irrelevant)
    S[3] = (S[1] - S[2]);
    S[2] += (S[1] - S[2]);

    // cout << S[2] << endl << G[2] << endl << P[2] << endl << endl;
    
    fout << S[3] << endl << G[3] << endl << P[3] << endl;
    // cout << S[3] << endl << G[3] << endl << P[3] << endl;
}