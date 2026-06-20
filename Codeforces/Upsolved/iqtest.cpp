#include <iostream>

using namespace std;

int main()
{
    int N, maze[100], oCount = 0, eCount = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        maze[i] = temp;
        if(temp % 2 == 0) {
            eCount++;           
        } else {
            oCount++;
        }
    }
    // Now cycle

    if(eCount == 1) {
        // Different Number is EVEN
        for(int i = 0; i < N; i++) {
            if(maze[i] % 2 == 0)
                cout << maze[i] << endl;
        }
    } else {
        // Different Number is ODD
        for(int i = 0; i < N; i++) {
            if(maze[i] % 2 == 1)
                cout << maze[i] << endl;
        }
    }

    return 0;
}