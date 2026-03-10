/*
ID: ayushn.2
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outputFile("friday.out");
    ifstream inputFile("friday.in"); // Setting Up Variables!!!
    int years;
    inputFile >> years;

    int currentYear = 1900;
    bool isLeap;
    int dayOfTheWeek = 5;                                    // Mon 0 Tue 1 Wed 2 Thurs 3 Fri 4 Sat 5 Sun 6     /* The Reason for the dayOfTheWeek being 5 is that the first 13'th was a Saturday! in 1900! */
    int month = 0;                                           // Starts on January
    int dayTrack[7] = {0, 0, 0, 0, 0, 0, 0};                 // Tracks Day Counter (what is outputted at the end)
    int monthMod[12] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3}; // Modulus for the differnet days
    int leapMod[12] = {3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};

    while (currentYear < 1900 + years)
    {

        if ((currentYear % 4 == 0 && currentYear % 100 != 0) || currentYear % 400 == 0)
            isLeap = true;

        if (isLeap == 1) // Leap Year
        {
            while (month < 12)
            {
                dayTrack[dayOfTheWeek]++;
                dayOfTheWeek = (dayOfTheWeek + leapMod[month]) % 7;
                month += 1;
            }
        }
        else // Non Leap Year
        {
            while (month < 12)
            {
                dayTrack[dayOfTheWeek]++;
                dayOfTheWeek = (dayOfTheWeek + monthMod[month]) % 7;
                month += 1;
            }
        }

        month = 0;      // Reset to January
        isLeap = false; // Reset isLeap
        currentYear++;  // Update CurrentYear
    }

    outputFile << to_string(dayTrack[5]);       //sat
    outputFile << " " + to_string(dayTrack[6]); // sun
    outputFile << " " + to_string(dayTrack[0]); // mon
    outputFile << " " + to_string(dayTrack[1]);
    outputFile << " " + to_string(dayTrack[2]);
    outputFile << " " + to_string(dayTrack[3]);
    outputFile << " " + to_string(dayTrack[4]) << endl;
    return 0;
}