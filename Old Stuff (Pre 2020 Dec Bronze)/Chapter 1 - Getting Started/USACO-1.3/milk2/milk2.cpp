/*
ID: ayushn.2
TASK: milk2
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

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

    int currentConsecutive = 0;
    int topConsecutive = 0;
    int topGap = 0;

    // Starting First Consecutive
    istringstream sso(inputs.at(1));
    string primNumFirst;
    string primNumSec;
    sso >> primNumFirst;
    sso >> primNumSec;
    currentConsecutive = stoi(primNumSec) - stoi(primNumFirst);


    for(int i = 1; i < farmerNum; i++) {

        string outgoingString = inputs.at(i);
        string incomingString = inputs.at(i + 1);
        
        istringstream ss(outgoingString);
        string firstNumOutgoing;
        string secondNumOutgoing;
        ss >> firstNumOutgoing;
        ss >> secondNumOutgoing;

        istringstream sss(incomingString);
        string firstNumIncoming;
        string secondNumIncoming;
        sss >> firstNumIncoming;
        sss >> secondNumIncoming;

        // cout << firstNumOutgoing << endl << secondNumOutgoing << endl << endl << firstNumIncoming << endl << secondNumIncoming << endl << endl;

        int diff = stoi(firstNumIncoming) - stoi(secondNumOutgoing);
        if (diff <= 0) {
            currentConsecutive += stoi(secondNumIncoming) - stoi(secondNumOutgoing);
            if ((stoi(secondNumIncoming) - stoi(firstNumIncoming)) > currentConsecutive) {
                currentConsecutive = (stoi(secondNumIncoming) - stoi(firstNumIncoming));
            }
        } else {
            if (currentConsecutive > topConsecutive) {
                topConsecutive = currentConsecutive;
            }
            currentConsecutive = stoi(secondNumIncoming) - stoi(firstNumIncoming);
            int currentGap = stoi(firstNumIncoming) -  stoi(secondNumOutgoing);
            if (currentGap > topGap) {
                topGap = currentGap;
            }
        }

    }
    if (currentConsecutive > topConsecutive) {
        topConsecutive = currentConsecutive;
    }
    // if (stoi(primNumFirst) == 2) {
    //     topConsecutive++;
    // }
    outputFile << topConsecutive << " " << topGap << endl;
    
    
}