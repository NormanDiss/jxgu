/*
ID: ayushn.2
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outputFile("friday.out");
    ifstream inputFile("friday.in");
    string line;
    inputFile >> line;
    int input = stoi(line);

    // keep count of the count for the different week
    int week[7] = {0, 0, 0, 0, 0, 0, 0};

    // keep track of the day week and year
    int currentDay = 1;
    int month = 1;

    int dayOfTheWeek = 0; // Mon Tue Wed Thu Fri Sat Sun
    int currentYear = 1900;

    while (currentYear < 1900 + input)
    {
        if (currentDay == 13)
        { 
            week[dayOfTheWeek]++; // Track Friday the 13's
        }

        // Update the dayOfTheWeek
        if (dayOfTheWeek == 6)
        {
            dayOfTheWeek = 0;
        }
        else
        {
            dayOfTheWeek++;
        }
        // Leap!!

        if (month == 2 && currentDay == 29) // February (Leap Year)
        {
            month = 3;
            currentDay = 1;
            continue;
        } else if (month == 2 && currentDay == 28)
        {
            if (currentYear % 4 == 0)
            {
                if (currentYear % 400 == 0)
                {
                    // 400 Leap Year
                    currentDay = 29;
                    continue;
                }
                else if (currentYear % 100 == 0)
                {
                    // 100 Non Leap Year
                    currentDay = 1;
                    month = 3;
                    continue;
                }
                else
                {
                    // Normal Leap Year
                    currentDay = 29;
                    continue;
                }
            }
        }


        // Update currentYear
        if (month == 12 && currentDay == 31)
        {
            currentYear++;
            month = 1;
            currentDay = 1;
            continue;
        } else if (currentDay == 31) {
            month ++;
            currentDay = 1;
            continue;
        } else if (currentDay == 30) {
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                    month ++;
                    currentDay = 1;
                    continue;
                } else if (month == 2) {
                    continue;
                } else {
                    currentDay = 31;
                    continue;
                } 
        } else {
            currentDay++;
            continue;
        }




    }

    outputFile << to_string(week[0]);
    outputFile << " " + to_string(week[1]);
    outputFile << " " + to_string(week[2]);
    outputFile << " " + to_string(week[3]);
    outputFile << " " + to_string(week[4]);
    outputFile << " " + to_string(week[5]);
    outputFile << " " << to_string(week[6]);

    return 0;
}