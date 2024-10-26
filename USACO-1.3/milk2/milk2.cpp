/*
ID: ayushn.2
TASK: milk2
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    /* Getting the Inputs */
    ofstream outputFile ("milk2.out");
    ifstream inputFile ("milk2.in");

    vector<string> inputs;
    string str;

    while (getline(inputFile, str))
    {
        if (str.size() > 0)
        {
            inputs.push_back(str); // Add amount of people
        }
    }

    /* Initializing Variables */
    int farmerNum = stoi(inputs[0]);
    
    
}