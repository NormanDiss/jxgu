/*
ID: ayushn.2
TASK: mixmilk
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct milk {
    int filled;
    int capacity;
};

int main()
{
    ofstream fout ("mixmilk.out");
    ifstream fin ("mixmilk.in");
    milk maze[3];
    for(int i = 0; i < 3; i++) {
        milk x;
        fin >> x.capacity >> x.filled;
        maze[i] = x;
    }
    for(int i = 0; i < 100; i++) {
        // Pour from i to i+1 mod 3

        // Next One
        maze[((i % 3) + 1) % 3].filled = min(maze[((i % 3) + 1) % 3].capacity, (maze[((i % 3) + 1) % 3].filled + maze[(i % 3)].filled));
        if((maze[((i % 3) + 1) % 3].filled + maze[(i % 3)].filled) > maze[((i % 3) + 1) % 3].capacity) {
            maze[(i % 3)].filled = (maze[((i % 3) + 1) % 3].filled + maze[(i % 3)].filled) % maze[((i % 3) + 1) % 3].capacity;  
        } else {
            maze[(i % 3)].filled = 0;
        }

    }
    cout << maze[0].filled << endl << maze[1].filled << endl << maze[2].filled << endl;



    fout << "NotSetYet" << endl;
    return 0;
    
}