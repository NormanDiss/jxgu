/*
ID: ayushn.2
TASK: runround
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isRunaround(string n) { // Most likely the strings will be generated with 
    int currentIndex = 0;
    vector<int> passed;
    while(passed.size() < n.size()) {
        int x = n.at(currentIndex);
        x -= 48;
        // cout << x << " | ";

        /* Adding to the Vector */
        for(int i  = 0; i < passed.size(); i++) {
            if(x == passed[i]) {
                // cout << "F" << endl;
                return false;
            }
            if(x == 0) {
                // cout << "F" << endl;
                return false;

            }

        }
        passed.push_back(x);
        /* Determining the New Position */
        int numbersToMoveUp = x % n.size();
        int newPosition = (currentIndex + numbersToMoveUp) % n.size();
        currentIndex = newPosition;
        // cout << ":" << currentIndex << " - ";
    }
    // Now for the final check
    if(currentIndex == 0) {
        // cout << "TRUE" << endl;
        return true;
    } else {
        // cout <<  "FALSE" << endl;
        return false;
    }
}



int main()
{
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    int N;
    fin >> N;
    int current = N + 1;
    while(true) {
        if(isRunaround(to_string(current))) {
            fout << current << endl;
            cout << current << endl;
            return 0;
        }
        current++;
    }
    return 1;
    
}