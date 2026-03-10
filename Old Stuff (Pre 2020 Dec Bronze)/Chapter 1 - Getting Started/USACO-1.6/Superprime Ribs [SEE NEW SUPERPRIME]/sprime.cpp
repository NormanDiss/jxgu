/*
ID: ayushn.2
TASK: sprime
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

bool checkPrime(int number) {
    int x = sqrt(number); // Check this once, and not on every execution
    for(int i = 2; i <= x; i++) {
        if(number % i == 0)
            return false;
    }
    return true;
}

vector<int> oneDigit() {
    vector<int> answer;
    answer.push_back(2);
    answer.push_back(3);
    answer.push_back(5);
    answer.push_back(7);
    return answer;
}

vector<int> twoDigit() {
    vector<int> answer;
    // Generate Primes
    int bases[4] = {2, 3, 5, 7};
    int oddNums[5] = {1, 3, 5, 7, 9};
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            int z = 10*bases[i] + oddNums[j];
            if(checkPrime(z)) {
                answer.push_back(z);
            }
        }
    }
    return answer;
}


int main()
{
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    int N;
    fin >> N;
    vector<int> one = oneDigit();
    vector<int> two = twoDigit();

    switch (N) {
        case 1:
            for(int i = 0; i < one.size() - 1; i++)   {
                fout << one[i] << endl;
            }
            break;
        case 2:
            for(int i = 0; i < two.size() - 1; i++)   {
                fout << two[i] << endl;
            }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
    }
    return 0;
    
}   