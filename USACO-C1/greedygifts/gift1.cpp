/*
ID: ayushn.2
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#inclu∂de <string>

using namespace std;

int main()
{
    ofstream outputFile("gift1.out");
    ifstream in("gift1.in");
    if (!in)
    {
        cout << "Cannot open input file.\n";
        return 1;
    }
    string str;
    vector<string> inputs;

    while (getline(in, str))
    {
        if (str.size() > 0)
        {
            inputs.push_back(str); // Add amount of people
        }
    }

    string inputsAT = inputs.at(0);
    int peopleNum = stoi(inputsAT);
    vector<string> namesAtIndex;
    for (int i = 1; i < peopleNum + 1; i++)
    {
        namesAtIndex.push_back(inputs.at(i)); // Add more names
    }

    int people[peopleNum]; // array to track how much money people have.
    for (int i = 0; i < peopleNum; i++)
    {
        people[i] = 0;
    }

    int wrapCount = 0;
    int position = peopleNum + 1; // Go through each person!
    while (wrapCount < peopleNum)
    {
        // Check Person
        if (position == inputs.size() - 1) {
            break;
        }
        string numberRAW = inputs.at(position + 1);

        istringstream ss(numberRAW);
        vector<int> splitRaw;

        do
        {
            string num;
            ss >> num;
            if (num == "")
            {
                break;
            }
            splitRaw.push_back(stoi(num));

        } while (ss); // Now there is a vector, splitRaw, which has [money, people]

        if (splitRaw.at(1) == 0)
        { // catch division by 0
            wrapCount++;
            continue;
            
        }

        int moneyToDivide = splitRaw.at(0) / splitRaw.at(1);
        int moneyToReturn = splitRaw.at(0) % splitRaw.at(1); // Calculating money to give and return

        // vector<string>::iterator giverIt = find(namesAtIndex.begin(), namesAtIndex.end(), inputs.at(position));
        // int indexOfGiver = distance(namesAtIndex.begin(), giverIt);

        int indexOfGiver;
        for (int i = 0; i < namesAtIndex.size(); i++) {
            if (namesAtIndex.at(i) == inputs.at(position)) {
                indexOfGiver = i;
                break;
            }
        }

        people[indexOfGiver] -= splitRaw.at(0);
        people[indexOfGiver] += moneyToReturn;
        position += 2; //now on first person!
        for (int i = 0; i < splitRaw.at(1); i++)
        {
            // vector<string>::iterator receiverIt = find(namesAtIndex.begin(), namesAtIndex.end(), inputs.at(position)); // this seems not to work for some reason on the USACO compiler, maybe a C++11 thing?? idk doing a for int loop works for now!
            // int indexOfReceiver = distance(namesAtIndex.begin(), receiverIt);

            int indexOfReceiver;

            for (int i = 0; i < namesAtIndex.size(); i++) {
                if (namesAtIndex.at(i) == inputs.at(position)) {
                    indexOfReceiver = i;
                    break;
                }
                
            }

            people[indexOfReceiver] += moneyToDivide;
            position += 1;
        }

        wrapCount++;
    }
    
    //now the money has been allocated, all that remains is to create strings and print them to the output file!!!!
    for(int i = 0; i < peopleNum; i++) {
        string outputVal = namesAtIndex.at(i) + " " + to_string(people[i]);
        outputFile << outputVal << endl;
    }

    return 0;
}
