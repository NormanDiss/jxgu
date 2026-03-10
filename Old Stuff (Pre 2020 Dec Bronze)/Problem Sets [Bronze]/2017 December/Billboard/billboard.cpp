/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{

    // Method, just create a large array, and then change values in that array, there are only about a million possiblites anyways.


    ofstream fout ("billboard.out");
    ifstream fin ("billboard.in");

    // Inputs
    int fx1, fy1, fx2, fy2, sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
    fin >> fx1 >> fy1 >> fx2 >> fy2 >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;

    vector<vector<int> > maze;

    for(int i = 0; i < 1000; i++) {
        vector<int> toPush;
        toPush.resize(1000);
        for(int j = 0; j < 1000; j++) {
            if(i <= fy2 && i > fy1 && j <= fx2 && j > fx1)
                toPush[j] = 1;
 
            if(i <= sy2 && i > sy1 && j <= sx2 && j > sx1)
                toPush[j] = 1;

            if(i <= ty2 && i > ty1 && j <= tx2 && j > tx1)
                toPush[j] = 0;


        }
        maze.push_back(toPush);
    }
    int cnt = 0;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if(maze[i][j] == 1)
                cnt++;
        }
    }


    fout << cnt << endl;
    return 0;
    
}