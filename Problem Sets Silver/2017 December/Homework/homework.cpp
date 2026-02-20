#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int N, arr[10000];
    ifstream fin("homework.in");
    ofstream fout("homework.out");
    for(int i = 0; i < N; i++)
        fin >> arr[i];
    // Rolling Sum
    int sum = 0;
    float avg[10000]; 
    for(int i = 0; i < N; i++) {
        sum += arr[i];
        float x = (float(sum)) / float(i);
        avg[i] = x;
        
    }
    
    
    return 0;
}