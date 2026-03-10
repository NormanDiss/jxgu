#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int optimal(int K, int X) {
    vector<int> front;
    vector<int> back;
    // Phase 1, populate front with values until you have enough to match K
    int currentSum = 0;
    for(int i = 1; i <= X; i++) {
        front.push_back(i);
        currentSum += i;
        if(currentSum >= K) {
            return i; // Return i this is the case where x is larger than the ending value
        }
    }
    // Now first counts up to X, second counts up to X
    back.push_back(X); // Unless previous case most optimal to end on K


}

int main() {
    ifstream fin("race.in");
    ofstream fout("race.out");
    int K, N, values[1000];
    fin >> K >> N;
    for(int i = 0; i < N; i++)
        fin >> values[i];
    


    return 0;
}