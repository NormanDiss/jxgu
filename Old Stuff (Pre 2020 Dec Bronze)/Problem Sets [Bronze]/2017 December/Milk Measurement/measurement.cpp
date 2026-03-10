/*
ID: ayushn.2
TASK: measurement
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

struct milkAdd {
    string cow;
    int milkToAdd;
};

int main()
{
    ofstream fout ("measurement.out");
    ifstream fin ("measurement.in");
    int N, temp, cowCount[3] = {7, 7, 7}, currentMax = -1, current = 0, oldCurrentMax, count = 0;
    fin >> N;
    
    map<int, milkAdd> maze;
    for(int i = 0; i < N; i++) {
        milkAdd toAdd;
        
        fin >> temp >> toAdd.cow >> toAdd.milkToAdd;
        maze.insert(pair<int, milkAdd>(temp, toAdd));
    }

    for(auto elem : maze) {
        // 1 = Mildred
        // 2 = Elsie
        // 3 = Bessie

        if(elem.second.cow == "Mildred") { // have to code like yandere cause frikin switch
            cowCount[0] += elem.second.milkToAdd;
        } else if(elem.second.cow == "Elsie") {
            cowCount[1] += elem.second.milkToAdd;
        } else if(elem.second.cow == "Bessie") {
            cowCount[2] += elem.second.milkToAdd;
        }

        oldCurrentMax = currentMax;
        
        for(int j = 0; j < 3; j++) {
            if(cowCount[j] > current){
                current = cowCount[j];
                currentMax = j;
            }
        }
        cout << oldCurrentMax << endl;
        cout << currentMax << endl << endl;
        if(oldCurrentMax != currentMax)
            count++;

    }



    cout << count << endl;
    fout << "NotSetYet" << endl;
    return 0;
    
}