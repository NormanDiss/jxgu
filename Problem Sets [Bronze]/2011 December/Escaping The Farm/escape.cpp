/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool ifCarry(vector<int> nums) {
    vector<string> strNums;
    for(int i = 0; i < nums.size(); i++) {
        strNums[i] = to_string(nums[i]);
    } 
}

int main()
{
    ofstream fout ("escape.out");
    ifstream fin ("escape.in");
    int N;
    fin >> N;
    int cows[N];
    for(int i = 0; i < N; i++) {
        fin >> cows[i];
    }



    fout << "NotSetYet" << endl;
    return 0;
    
}