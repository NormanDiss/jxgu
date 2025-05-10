/*
ID: ayushn.2
TASK: sort3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    int N;
    fin >> N;
    vector<int> rawInput;
    vector<int> sorted;
    for(int i = 0; i < N; i++) {
        int x;
        fin >> x;
        rawInput.push_back(x);
        sorted.push_back(x);
    }
    sort(sorted.begin(), sorted.end()); 
    int ones = count(rawInput.begin(), rawInput.end(), 1);
    cout << ones << endl;
    int twos = count(rawInput.begin(), rawInput.end(), 2);
    cout << twos << endl;
    int threes = count(rawInput.begin(), rawInput.end(), 3);
    cout << threes << endl;
    /* 1 -> 3, 2 -> 3, 2 -> 1, 3 -> 1, 1 -> 2, 3 -> 2*/
    int oneToThree, twoToThree, twoToOne, threeToOne, oneToTwo, threeToTwo;
    for(int i = 0; i < sorted.size(); i++) { 
        if(i < ones && rawInput[i] == 2) {
            oneToTwo++;
        }
        if(i < ones && rawInput[i] == 3) {
            oneToThree++;
        }

        if(i > ones && i < (ones + twos) && rawInput[i] == 1) {
            twoToOne++;
        }

        if(i > ones && i < (ones + twos) && rawInput[i] == 3) {
            twoToThree++;
        }
        if(i > (ones + twos) && i < (ones + twos + threes) && rawInput[i] == 1) {
            threeToOne++;
        }

        if(i > (ones + twos) && i < (ones + twos + threes) && rawInput[i] == 2) {
            threeToTwo++;
        }

    }
    // So now we know which ones are out of place, we can now try to do operations on them
    // For the direct swaps, its just the smaller of the two for the two "reciprocal amounts"
    int directSwap = 0;
    directSwap += min(oneToThree, threeToOne) + min(oneToTwo, twoToOne) + min(twoToThree, threeToTwo);
    // As for the indirect swaps, as they have to happen twice, the discrepancy between two reciprocal amounts should be equal to the discrepancy between the other three, but since all the swaps happen twice, its just that x2.
    int indirectSwap = 0;
    indirectSwap += max(oneToThree, threeToOne) - min(oneToThree, threeToOne);
    int toReturn = directSwap + (2*indirectSwap);
    fout << toReturn << endl;
    return 0;
    
}