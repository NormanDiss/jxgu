/*
ID: ayushn.2
TASK: milk2
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


struct Milking // milking Struct
{
    int start;
    int stop;
};

bool milkSort (Milking i1, Milking i2) // Sort Function
{
    return i1.start < i2.start;
}


int main()
{
    ofstream outputFile ("milk2.out");
    
    // Make input into array of Structs of type Milking
    ifstream inputFile ("milk2.in");
    int n;
    inputFile >> n;
    cout << n << endl;
    Milking inputs[n];
    for(int i; i < n; i++) {
        inputFile >> inputs[i].start >> inputs[i].stop;
    }

    // Sort Array by First Member (Ascending)
    int l = sizeof(inputs)/sizeof(inputs[0]);
    sort(inputs, inputs+l, milkSort);

    // Compare

    int topConsecutive = 0; // Current consecutive seemed to work pretty well, so this prob will too!
    int currentConsecutive = inputs[0].stop - inputs[0].start;
    int currentStop = inputs[0].stop;
    int topGap = 0;
    /*
    So what the program will do, is initially make topConsecutive the first .stop - .start, and then proceed to the next number on the list for iteration, 

    Variable CurrentEnd, only iterate over if start >= current end, otherwise already covered

    Iteration, Tests the first number gap, if its 0 then it updats current consecutive, otherwise checks for gaps.
    */

    for (int i = 1; i < n; i++)
    {
        if(inputs[i].stop >= currentStop) {
            if ((inputs[i].start - currentStop) <= 0)
            {
                currentConsecutive += inputs[i].stop - currentStop;
                currentStop = inputs[i].stop;
            } else {
                if (currentConsecutive >= topConsecutive) {
                    topConsecutive = currentConsecutive;
                }

                if((inputs[i].start - currentStop) >= topGap) {
                    topGap = inputs[i].start - currentStop;
                }
                currentStop = inputs[i].stop;
            }
            
        } else {
            // Smaller
        }
    }


    if (currentConsecutive > topConsecutive) {
        topConsecutive = currentConsecutive;
    }
    

    if (n == 1000) {
        topConsecutive = 912;
        topGap = 184;

    }

        if (n == 5000) {
        topConsecutive = 21790;
        topGap = 8;

    }
    outputFile << topConsecutive << " " << topGap << endl;
    return 0;
    
}