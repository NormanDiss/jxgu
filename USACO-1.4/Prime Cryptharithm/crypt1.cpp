/*
ID: ayushn.2
TASK: crypt1
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool checkSet(vector<int> v, int n) {
    string z = to_string(n);
    cout << z << endl;
    for(int i = 0; i < z.length(); i++) {
        int x = z.at(i);
        x -= 48;

        if(find(v.begin(), v.end(), x) != v.end()) {
            continue;
        } else {
            return false;
        }
        
    }
    return true;
}


int main()
{
    ofstream outputFile ("crypt1.out");
    ifstream inputFile ("crypt1.in");
    int N;
    inputFile >> N;
    vector<int> digits;    
    for(int i = 0; i < N; i++) {
        int z;
        inputFile >> z;
        digits.push_back(z);
    }
    int count = 0; // This is for counting stuff
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                for(int l = 0; l < N; l++) {
                    for(int m = 0; m < N; m++) {
                        // ijk * lm
                        int x = (digits.at(i)*100) + (digits.at(j)*10) + (digits.at(k));
                        int y = (digits.at(l) * 10) + (digits.at(m));
                        int product = x * y;
                        int firstSum = x * (digits.at(l));
                        int secondSum = x * (digits.at(m));
                        if(to_string(product).length() != 4) {  
                            continue;
                        }
                        if(to_string(firstSum).length() != 3) {  
                            continue;
                        }
                        if(to_string(secondSum).length() != 3) {  
                            continue;
                        }
                        if(checkSet(digits, product)) {
                            // Do Nothing
                        } else {
                            continue;
                        }
                        if(checkSet(digits, firstSum)) {
                            // Do Nothing
                        } else {
                            continue;
                        }
                        if(checkSet(digits, secondSum)) {
                            // Do Nothing
                        } else {
                            continue;
                        }
                        count++;
                        
                    }
                }
            }
        }
    }

    outputFile << count << endl;
    return 0;
    
}