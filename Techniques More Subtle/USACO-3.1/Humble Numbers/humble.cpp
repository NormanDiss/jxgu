/*
ID: ayushn.2
TASK: humble
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    int K, N;
    fin >> K >> N;
    vector<int> maze;
    maze.resize(K);
    for(int i = 0; i < K; i++)
        fin >> maze[i];
    
    vector<int> outputList;

    vector<int> count;
    for(int i = 0; i < K; i++)
        count.push_back(0);
    
    outputList.push_back(1);


    while(outputList.size() < (N + 1)) {
        vector<int> tempNum;
        for(int i = 0; i < K; i++)
            tempNum.push_back(maze[i] * outputList[count[i]]);
        sort(tempNum.begin(), tempNum.end());
        outputList.push_back(tempNum[0]);
    }

    cout << outputList[-1] << endl;

    fout << "NotSetYet" << endl;
    return 0;
    
}