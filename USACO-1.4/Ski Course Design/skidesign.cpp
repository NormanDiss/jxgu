/*
ID: ayushn.2
TASK: skidesign
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



int main()
{
    ofstream outputFile ("skidesign.out");
    ifstream inputFile ("skidesign.in");
    int N, min, max, cost, currentMinimum = ;
    inputFile >> N;
    int skislope[N];
    for(int i = 0; i < N; i++) {
        inputFile >> skislope[i];
    }

    for(int min = 0; min <= 83; min++) {
        max = min + 17;
        cost = 0;

        for(int i = 0; i < N; i++) {

            if(skislope[i] >= min && skislope[i] <= max) {
                // Do Nothing (Already In Range)
            } else {
                if(skislope[i] > max ) {
                    // Skislope is too big!
                    cost += (skislope[i] - max)*(skislope[i] - max);
                } 
                if(skislope[i] < min) {
                    // Skislope is too small!
                    cost += (min - skislope[i])*(min - skislope[i]);
                }
            }
            
        }

        if(cost <= currentMinimum) {
            currentMinimum = cost;
        }
    }
    


    outputFile << cost << endl;
    return 0;
    
}