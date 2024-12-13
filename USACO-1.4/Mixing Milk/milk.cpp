/*
ID: ayushn.2
TASK: milk
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
struct milk 
{
    int unit, amount;
};
bool compareInterval(milk i, milk o) 
{
    return (i.unit < o.unit );
}

int main()
{
    ofstream outputFile ("milk.out");
    ifstream inputFile ("milk.in");
    int n, m;
    inputFile >> n >> m;

    // Initializing Variables
    int currentCost = 0;
    int milkLeft = n;
    int cnt = 0;
    // Vector Stuff
    vector<milk> farmerList;
    for(int i = 0; i < m; i++) {
        int x, y;
        inputFile >> x >> y;
        milk toPush = {x, y};
        farmerList.push_back(toPush);
    }
    sort(farmerList.begin(), farmerList.end(), compareInterval);
    while(milkLeft > 0) {
        if(farmerList[cnt].amount > milkLeft) {
            currentCost += milkLeft*farmerList[cnt].unit;
            milkLeft = 0;
        } else {
            milkLeft -= farmerList[cnt].amount;
            currentCost += farmerList[cnt].unit*farmerList[cnt].amount;
        }
        cnt++;
    }
    outputFile << currentCost << endl;
    return 0;
    
}