/*
ID: ayushn.2
TASK: gift1
LANG: C++                 
*/


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outputFile ("filename.out");
    ifstream inputFile ("filename.in");
    int line1;
    string line2;
    inputFile >> line1 >> line2;

    outputFile << "NotSetYet" << endl;
    return 0;
    
}