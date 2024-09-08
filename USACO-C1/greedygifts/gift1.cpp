/*
ID: ayushn.2
TASK: test
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ofstream outputFile("gift1.out");
    ifstream in("gift1.in");
    string str;
    vector<string> inputs;

    while (getline(in, str))
    {
        if (str.size() > 0)
        {
            inputs.push_back(str);
        }
    }

    // for (int i = 0; i < inputs.size(); i++) {
    //     cout << inputs.at(i) << endl;
    // }

    // -- Now at this point in the code inputs is a vector of all the people!!! --
    string inputsAT = inputs.at(0);
    int peopleNum = stoi(inputsAT);
    vector<string> namesAtIndex;
    for (int i = 1; i < peopleNum + 1; i++)
    {
        namesAtIndex.push_back(inputs.at(i));
    }

    // for (int i = 0; i < namesAtIndex.size(); i++) {
    //     cout << namesAtIndex.at(i) << endl;
    // }

    int people[peopleNum]; // array to track how much money people have.
    for (int i = 0; i < peopleNum; i++)
    {
        people[i] = 0;
    }

    // Open Loop to go through each person.
    int wrapCount = 0;
    int position = peopleNum;
    while (wrapCount < peopleNum)
    {
        // Check Person
        string numberRAW = inputs.at(position + 2);

    istringstream ss(numberRAW);
        vector<int> splitRaw;
        do
        {
            string num;
            ss >> num;
            splitRaw.push_back(stoi(num));
        } while (ss);
        // Now there is a vector, splitRaw, which has [money, people]

        vector<string> currentslice;
        // currentslice = copy(inputs.begin() + position);
    }

    outputFile << "NOTSETYET" << endl;
    return 0;
}