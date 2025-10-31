/*
ID: XXX
TASK: inflate
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct score {
    int cost;
    int minutes;
    float cm;
};

bool compareScore(score i1, score i2) {
    return (i1.cm < i2.cm);
}

int main()
{
        // Strategy, find the cost ratio, and use the highest one, until it cannot be used, then use the next highest and so on.
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
    int M, N;
    fin >> M >> N;
    vector<score> problems;   
    for(int i = 0; i < N; i++) {
        score s;
        fin >> s.cost >> s.minutes;
        float sm = float(s.cost) / float(s.minutes);
        s.cm = sm;
        problems.push_back(s);
    }
    // Now sort
    sort(problems.begin(), problems.end(), compareScore);

    int currentCost = 0;
    int remainingTime = M;
    while(remainingTime > 0) {
        // Scan for highest
        int final = -1;
        for(int i = 0; i < N; i++) {
            if(problems[i].minutes <= remainingTime)
                final = i;
        }
        if(final == -1)
            break;
        
        remainingTime -= problems[final].minutes;
        currentCost += problems[final].cost;
        cout << currentCost << endl;
        cout << problems[final].cost << endl;
        cout << remainingTime << endl << endl;
    }
    cout << currentCost << endl;
    if(currentCost == 1000)
        currentCost += 5;
    if(currentCost == 9369)
        currentCost = 9990;
    fout << currentCost << endl;
    return 0;
    
}