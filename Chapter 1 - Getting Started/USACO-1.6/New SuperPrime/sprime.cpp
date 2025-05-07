/*
ID: ayushn.2
TASK: sprime
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPrime(int number) {
    int x = sqrt(number); // Check this once, and not on every execution
    for(int i = 2; i <= x; i++) {
        if(number % i == 0)
            return false;
    }
    return true;
}


int main()
{
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    int N;
    fin >> N;
    vector<int> currentPrimes;
    currentPrimes.push_back(2);
    currentPrimes.push_back(3);
    currentPrimes.push_back(5);
    currentPrimes.push_back(7);
    int odd[5] = {1, 3, 5, 7, 9};

    for(int i = 1; i < N; i++) { // This will dictate the current layer
        vector<int> layers; // This will dictate the current N digit numbers, later will be copied into currentPrimes
        for(int j = 0; j < 5; j++) { // This will dictate which odd number is added to the end
            for(int k = 0; k < currentPrimes.size(); k++) { // This will dictate which number is changed, goes through all of them
                int z = currentPrimes[k] * 10 + odd[j]; // Create a new number with the odd number to the back
                if(checkPrime(z)) {
                    layers.push_back(z); // Append it to current prime
                }
            }

        }
        currentPrimes = layers;
    }
    sort(currentPrimes.begin(), currentPrimes.end());
    for(int i = 0; i < currentPrimes.size(); i++) {
        fout << currentPrimes[i] << endl;
    }

    return 0;
    
}   