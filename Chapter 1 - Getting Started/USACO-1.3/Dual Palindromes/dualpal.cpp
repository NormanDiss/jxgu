/*
ID: ayushn.2
TASK: dualpal
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
    ofstream outputFile ("dualpal.out");
    ifstream inputFile ("dualpal.in");
    int n, number;
    inputFile >> n;
    inputFile >> number;
    int currentNum = number + 1;
    // vector, to initialize the first N numbers afterward.
    vector<int> listIt;

    while(listIt.size() < n) {
        int correct = 0;
        for(int i = 2; i <= 10; i++) {
            string x = convertBase(i, currentNum);
            bool y = checkPal(x);
            if(y == true) {
                correct++;
            }
        }
        if(correct >= 2) {
            listIt.push_back(currentNum);
        }
        currentNum++;
    }
    if(n != listIt.size()) {
        cout << "OPERATION FAILED OUTPUTING CORRUPTED DATA" << endl;
    }
    for(int i = 0; i < n; i++) {
        outputFile << listIt.at(i) << endl;
    }
    
    return 0;
    
}