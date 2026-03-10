#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int K, N, maze[10][20];
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    fin >> K >> N;
    cout << K << N << endl;
    for(int i = 0; i < K; i++){
        for(int j = 0; i < N; i++) {
            fin >> maze[K][N];
        }
    }
    // Check all pairs
    int soln = 0;
    for(int i = 1; i <= N; i++) {
        cout << "i is now: " << i << endl; 
        for(int j = (i + 1); j <= N; j++) {
            cout << "j is now: " << j << endl;
            // Check Each Set 
            int Ifirst = 0; // record number of times I is first, then compare against K sets
            for(int a = 0; a < K; a++) {
                // In Each Set
                int posI, posJ;
                for(int b = 0; b < N; b++) {
                    cout << "b: " << b << " " << maze[a][b] << endl;
                    if(maze[a][b] == i) {
                        posI = b;
                        cout << "found i!" << endl;
                    }
                    if(maze[a][b] == j) {
                        posJ = b;
                        cout << "found j!" << endl;
                    }
                }
                if(posI > posJ)
                    Ifirst++;

            }
            if(Ifirst == 0 || Ifirst == K) {
                soln++;
                cout << i << j << endl;
            }

            
        }
    }
    cout << soln << endl;
    
    return 0;
}