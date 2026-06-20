/*
ID: ayushn.2
TASK: test
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool checkPal(string string1) {
    string stringRev = string1;
    reverse(stringRev.begin(), stringRev.end());
    if (stringRev == string1) {
        return true;
    } else {
        return false;
    }
    
    
}
string convertBase(int base, int num) {

    const string digits("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    bool is_neg = num < 0;
    string result;
    for (; num; num /= base) {
        // Note: abs() is done on each digit instead of the whole num 
        // to preserve the full range of int
        result.insert(result.begin(), digits[abs(num % base)]);
    }
    if (is_neg)
        result.insert(result.begin(), '-');
    
    return result;


}
int main()
{
    ofstream outputFile ("palsquare.out");
    ifstream inputFile ("palsquare.in");
    int base;
    inputFile >> base;
    
    // Generate the palindromes for the first 300 numbers, then puts them in base

    for(int i = 0; i <= 300; i++) {
        int squared = i*i;
        string converted = convertBase(base, squared);
        bool result = checkPal(converted);
        if(result == true) {
            string iConverted = convertBase(base, i);
            string formatted = iConverted + " " + converted;
            outputFile << formatted << endl;
        }
        
    }




    
    return 0;
    
}