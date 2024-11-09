/*
ID: ayushn.2
TASK: namenum
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
string returnList(string s) {
    string returnString = "";
    for(char& c : s) {
        if(c == 'A' ||c == 'B'||c == 'C' ) {
            returnString.append("2");
        }
        if(c == 'D' ||c == 'E'||c == 'F' ) {
            returnString.append("3");
        }
        if(c == 'G' ||c == 'H'||c == 'I' ) {
            returnString.append("4");
        }
        if(c == 'J' ||c == 'K'||c == 'L' ) {
            returnString.append("5");
        }
        if(c == 'M' ||c == 'N'||c == 'O' ) {
            returnString.append("6");
        }
        if(c == 'P' ||c == 'R'||c == 'S' ) {
            returnString.append("7");
        }
        if(c == 'T' ||c == 'U'||c == 'V' ) {
            returnString.append("8");
        }
        if(c == 'W' ||c == 'X'||c == 'Y' ) {
            returnString.append("9");
        }
        if(c == 'Q' || c == 'Z') {
            returnString.append("~");
        }
    }
    return returnString;
}
int main()
{
    ofstream outputFile ("namenum.out");
    ifstream inputFile ("namenum.in");
    string line1;
    inputFile >> line1;
    vector<string> outputList;
    ifstream dict ("dict.txt");
    for(int i=0; i < 4617; i++) {
        string s;
        dict >> s;
        if (s.length() == line1.length()){
            if(returnList(s) == line1) {
                outputList.push_back(s);
            }
        }
    }
    
    for(int c = 0; c < outputList.size(); c++) {
        outputFile << outputList.at(c) << endl;
    }
    if(outputList.size() == 0) {
        outputFile << "NONE" << endl;
    }
    return 0;
    
}