/*
ID: ayushn.2
TASK: hamming
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

int binaryToDecimal(int n) 
{ 
    int num = n; 
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

int hammingDistance(string sOne, string sTwo) {
    int hammingDist = 0;
    for(int i = 0; i < sOne.size(); i++) {
        if(sOne.at(i) != sTwo.at(i))
            hammingDist++;
    }
    return hammingDist;
}

bool checkWithAll(string hamming, vector<string> hammingCodes, int D) {
    // cout << "Checking: " << hamming << " ";
    for(int i = 0; i < hammingCodes.size(); i++) {
        if(hammingDistance(hamming, hammingCodes[i]) < D) {
            // cout << "Not Found :c" << endl;
            return false;
        }
    }
    // cout << "Found!" << endl;
    return true;
}

using namespace std;

int main()
{
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    int N, B, D;
    fin >> N >> B >> D;
    // Generate Binary Numbers Up to 2^B - 1
    map<int, string> check;
    vector<string> hammingCodes;
    string originalZeroCode = "";
    for(int i = 0; i < B; i++) {
        originalZeroCode += "0";
    }
    hammingCodes.push_back(originalZeroCode);

    int n = pow(2, B) - 1;
    queue<string> q;
    q.push("1");
    while(n--)
    {
        string s1 = q.front();
        q.pop();
        string z = s1; // Random variable to store data with to append 0's to the end.
        while(z.length() < B) {
            z += "0";
        }

        /* Check if needed to be added*/
        check.insert(pair<int, string>(binaryToDecimal(stoi(z)), z));
        // Do z, but with a 0 at the front instead of a 1
        z.replace(0, 1, "0");
        check.insert(pair<int, string>(binaryToDecimal(stoi(z)), z));
        string s2 = s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));

    }
    for(map<int, string>::const_iterator it = check.begin(); it != check.end(); it++) {
        if(hammingCodes.size() == N) {
            break;
        }
        // cout << it->first << " : ";
        // cout << it->second << endl; 
        string x = it->second;
        if(checkWithAll(x, hammingCodes, D)) {
            hammingCodes.push_back(x);
        }
        
    }
    fout << "0";
    int currentSum = 1;
    for(int i = 1; i < N; i++) {
        if(currentSum == 10) {
            fout << endl;
            currentSum = 0;
        } else {
            fout << " ";
        }

        fout << binaryToDecimal(stoi(hammingCodes[i])) ;

        currentSum++;
    }
    fout << endl;
    return 0;

}