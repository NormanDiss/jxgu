/*
ID: ayushn.2
TASK: test
LANG: C++                 
*/


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outputFile ("filename.out");
    ifstream inputFile ("filename.in");
    string line1, line2;
    inputFile >> line1 >> line2;

    outputFile << "NotSetYet" << endl;
    return 0;
    
}