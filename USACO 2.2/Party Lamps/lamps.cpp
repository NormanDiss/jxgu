/*
ID: ayushn.2
TASK: lamps
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int binaryToDecimal(string n) 
{ 
    int num = stoi(n); 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
    } 
  
    return dec_value; 
}

bool sortBinary(string s1, string s2) {
    int s1DEC = binaryToDecimal(s1);
    int s2DEC = binaryToDecimal(s2);
    return (s1DEC < s2DEC);
}
  
string buttonOne(string starter) {
    for(int i = 0; i < starter.length(); i++) {
        if(starter.at(i) == '1') {
            starter.at(i) = '0';
        } else {
            starter.at(i) = '1';
        }
    }
    return starter;
}

string buttonTwo(string starter) {
    for(int i = 0; i < starter.length(); i+=2) {
        if(starter.at(i) == '1') {
            starter.at(i) = '0';
        } else {
            starter.at(i) = '1';
        }
    }
    return starter;
}

string buttonThree(string starter) {
    for(int i = 1; i < starter.length(); i+=2) {
        if(starter.at(i) == '1') {
            starter.at(i) = '0';
        } else {
            starter.at(i) = '1';
        }
    }
    return starter;
}

string buttonFour(string starter) {
    for(int i = 0; i < starter.length(); i+=3) {
        if(starter.at(i) == '1') {
            starter.at(i) = '0';
        } else {
            starter.at(i) = '1';
        }
    }
    return starter;
}

string doToo(string fourDigit, string whatToDoWith) {
    string toReturn = whatToDoWith;
    // in form 0000
    if(fourDigit.at(0) == '1')
        toReturn = buttonOne(toReturn);
    if(fourDigit.at(1) == '1')
        toReturn = buttonTwo(toReturn);
    if(fourDigit.at(2) == '1')
        toReturn = buttonThree(toReturn);
    if(fourDigit.at(3) == '1')
        toReturn = buttonFour(toReturn);
    return toReturn;
}

vector<string> generateAll(int length, int count) {
    string starter = "";
    vector<string> toReturn;
    for(int i  = 0; i < length; i++) {
        starter += "1";
    }
    string fIt[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
    for(int i = 0; i < 16; i++) {
        string s = fIt[i];
        int cnt = 0;
        for(int j = 0; j < 4; j++) {
            if(s.at(j) == '1') {
                cnt += 1;
            }
        }
        // So S is broken
        if(count == cnt) {
            toReturn.push_back(doToo(s, starter));
        }
    }
    return toReturn;

}

int main()
{
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    int N, C;
    fin >> N >> C;
    vector<int> on;
    vector<int> off;
    bool isOff = false;
    while(fin) {
        int x;
        fin >> x;
        if(x == -1) {
            isOff = true;
            continue;
        }
        if(isOff) {
            off.push_back(x);
            continue;
        } else {
            on.push_back(x);
            continue;
        }
        
    }
    /*
    What needs to be done:

    Use the above functions to generate all possibilities, then check their count.

    Then, check the positions of the "on" and "off" vectors, to make sure they are correct.
    */
    int c = C % 4;
    vector<string> toCheck = generateAll(N, c);
    vector<string> verifyOne;
    vector<string> verifyTwo;
    
    for (int i = 0; i < on.size(); i++) {
        int key = on[i] - 1;
        for (int j = 0; j < toCheck.size(); j++) {
            if(toCheck[j].at(key) == '0') {
                verifyOne.push_back(toCheck[j]);
                cout << toCheck[j] << endl;
            }
       }
    }

    if(on.size() == 0)
        verifyOne = toCheck;

    for (int i = 0; i < off.size(); i++) {
        int key = off[i] - 1;
        for (int j = 0; j < verifyOne.size(); j++) {
            if(verifyOne[j].at(key) == '0') {
                verifyTwo.push_back(verifyOne[j]);
            }
       }
    }
    
    if(off.size() == 0) {
        verifyTwo = verifyOne;
    }
    
    if(verifyTwo.size() == 0) {
        cout << "IMPOSSIBLE" << endl;
        fout << "IMPOSSIBLE" << endl;
        return 0;
    }

    /* Sort the Expression */
    sort(verifyTwo.begin(), verifyTwo.end(), sortBinary);
    for (int i = 0; i < verifyTwo.size(); i++) {
        cout << verifyTwo[i] << endl;
        fout << verifyTwo[i] << endl; 
    }
    return 0;
    
}