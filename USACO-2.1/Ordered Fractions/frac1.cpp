/*
ID: ayushn.2
TASK: frac1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

struct keyValuePair {
    float key;
    string value;
};

int gcd(int a, int b) 
{ 
    // 0 case is not needed, as will never be 0
    // base case 
    if (a == b) 
        return a; 

    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 

bool compareTwoKeys(keyValuePair a, keyValuePair b) {
    return a.key < b.key;
}

int main()
{
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");

    vector<keyValuePair> fracts;
    // Add 1/1 and 0/1
    keyValuePair zeroOne;
    zeroOne.key = 0.0;
    zeroOne.value = "0/1";
    keyValuePair oneOne;
    oneOne.key = 1.0;
    oneOne.value = "1/1";
    fracts.push_back(zeroOne);
    fracts.push_back(oneOne);

    int N;
    fin >> N;
    for(int i = 1; i <= N; i++) {
        // Denominator
        for(double j = 1.0; j < i; j++) {
            keyValuePair toInsert;
            // Numerator
            if(gcd(i, j) != 1) {// Make sure that its a common lowest term fraction
                continue;
            } else {
            string denom = to_string(i);
            int x = j;
            string numen = to_string(x);
            string value = numen + "/" + denom; // Janky string format
            float key = j/i;
            toInsert.value = value;
            toInsert.key = key;
            fracts.push_back(toInsert);
            }            
        }
    }
    sort(fracts.begin(), fracts.end(), compareTwoKeys);
    for(int i = 0; i < fracts.size(); i++) {
        fout << fracts[i].value << endl;
    }
    return 0;
    
}