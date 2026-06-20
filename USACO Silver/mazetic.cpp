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
int maze[25][25] = {0}; // 0 blank, 1 = wall, 2 = block

struct moved {
    string letter; // 1 = O, 2 = M;
    int x, y;
};

void dfs(int x, int y) {
    if(x >= 25 || y >= 25) return; // bounds
    if(x < 0 || y < 0) return; // bounds
    if(maze[y][x] == 1) return; // wall
    if(maze[y][x] == 0) {
        dfs(x, y+1);
        dfs(x, y-1);
        dfs(x+1, y);
        dfs(x-1, y);
    }
}

int main () {
    ifstream cin("maze.in");
    cin >> N;
    vector<string> mazes; mazes.resize(N);
    moved moves[N][N];
    int bessie[2];
    FOR(i, N) { cin >> mazes[i]; }
    FOR(i, N) {
        for(int j = 0; j < N; j ++) {
            if(mazes[i][j*3] == '#') {
                maze[i][j] = 1;
            } else if(mazes[i][j*3] == 'O' || mazes[i][j*3] == 'M'){
                maze[i][j] = 2;
                moved z;
                z.y = int(mazes[i][j*3 + 1]);
                z.x = int(mazes[i][j*3 + 2]);
                z.letter = mazes[i][j*3];
                moves[i][j] = z;
            }  else {
                bessie[1] = i;
                bessie[0] = j;
            }
        }
    }

    // Floodfill through maze, collecting moves
    cout << bessie[0] << ":" << bessie[1] << endl;
    FOR(i, N) {
        FOR(j, N) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}