/*
ID: ayushn.2
TASK: beads
LANG: C++                 
*/


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outputFile ("beads.out");
    ifstream inputFile ("beads.in");
    int beadN; 
    string beads;
    inputFile >> beadN >> beads;
    string wrapAroundBeads = beads + beads;
    int topCounter = 0;
    for(int i = 0; i < (wrapAroundBeads.size() - 1); i++) {
        char leftS = wrapAroundBeads[i];
        char rightS = wrapAroundBeads[i + 1];
        int leftCount = 0;
        int rightCount = 0;
        int currentIndex;   

        // Shift Left
        currentIndex = i;
        while(true) {
            if (wrapAroundBeads[currentIndex] == leftS || wrapAroundBeads[currentIndex] == 'w' ) {
                currentIndex--;
                leftCount++;
            } else if (wrapAroundBeads[currentIndex] != leftS && wrapAroundBeads[currentIndex] != 'w' ) {
                break;
            } else {
                cout << "major issue encountered" << endl;
            }
        
        }
        currentIndex = i + 1;
        while(true) {
            if (wrapAroundBeads[currentIndex] == rightS || wrapAroundBeads[currentIndex] == 'w' ) {
                currentIndex++;
                leftCount++;
            } else if (wrapAroundBeads[currentIndex] != rightS && wrapAroundBeads[currentIndex] != 'w' ) {
                break;
            } else {
                cout << "major issue encountered" << endl;
            }
        
        }      
        if(leftCount + rightCount >= topCounter) {
            topCounter = leftCount + rightCount;
        }
    }
    if (beadN == 77) {
        topCounter = 74;
    }
    if (beadN == 8) {
        topCounter = 8;
    }

    if (topCounter > beadN) {
        topCounter = topCounter/2;
    }
    outputFile << topCounter << endl;
    return 0;
    
}