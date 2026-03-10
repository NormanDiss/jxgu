/*
ID: ayushn.2
TASK: fact4
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int firstFromRight(int val) {
    string x = to_string(val);
    while(x.back() == '0')     // First eliminate all 0's to the right
        x.pop_back();
    while(x.size() > 5)     // Then resize into a 5 digit number
        x.erase(0,1); 
    return stoi(x);
}

int main()
{
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");
    int N, currentVar;
    fin >> N;
    currentVar = 1;
    

    for(int i = 1; i <= N; i++) {
        currentVar *= i;
        currentVar = firstFromRight(currentVar);

    }
    fout << to_string(currentVar).back() << endl;

    return 0;
    
}