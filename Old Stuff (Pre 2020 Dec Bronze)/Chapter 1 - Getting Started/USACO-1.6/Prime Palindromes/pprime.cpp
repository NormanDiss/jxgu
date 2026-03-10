/*
ID: ayushn.2
TASK: pprime
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
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

int makePal(int x, bool isOdd) {
    if(isOdd) {
        string y = to_string(x);
        string z = y;
        string h = y.substr(0, y.length() - 1);
        reverse(h.begin(), h.end()); 
        return stoi(y + h);
    } else {
        string y = to_string(x);
        string z = y;
        reverse(y.begin(), y.end()); 
        return stoi(z + y);

    }
}


int main()
{
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    int N, M;
    fin >> N;
    fin >> M;
    vector<int> primePals;

    // Create Palindromes
    int x = to_string(M).length(); 

    int cnt = 0;
    while(true) {
        int a = makePal(cnt, 0);
        int b = makePal(cnt, 1);
        if(b > M) {
            break;
        }
        if(a <= M && a >= N) {
            if(checkPrime(a)) {
                primePals.push_back(a);
            }
        }

        if(b <= M && b >= N) {
            if(checkPrime(b)) {
                primePals.push_back(b);
            }
        }
        cnt ++;
    }
    // Sort Vector
    sort(primePals.begin(), primePals.end());
    for(int i = 0; i < primePals.size(); i++) {
        fout << primePals.at(i) << endl;
    }

}
    