/*
ID: ayushn.2
TASK: ariprog
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
bool checkProg(vector<int> bisquares, int startIndex, int gap, int duration) {
    for(int i = 0; i < duration; i++) {
         int z = bisquares[startIndex] + (i * gap);
         // faster iteration
         bool found = false;
         for(int i = startIndex; i < bisquares.size(); i++) {
            if(bisquares[i] == z)
                found = true;
         }
         if(found == false) 
            return false;
    }
    return true;
}

int main()
{
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    int N, M;
    fin >> N;
    fin >> M;
    
    vector<int> bisquares;
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= M; j++) {
            int z = i*i + j*j; // Generate Bisquare
            if(find(bisquares.begin(), bisquares.end(), z) == bisquares.end()) // Check if in list
                bisquares.push_back(z);
        }
    }
    sort(bisquares.begin(), bisquares.end()); // Bisquares list sorted and ready
    // iterate over all possible
    vector<string> toPrint;
    for(int i = 0; i < M + 1; i++) {
        for(int j = 0; j < M; j++) {
            if(checkProg(bisquares, i, j, N)) {
                fout << bisquares[i];
                fout << " ";
                fout << j << endl;
            }
        }
    }

    return 0;
    
}