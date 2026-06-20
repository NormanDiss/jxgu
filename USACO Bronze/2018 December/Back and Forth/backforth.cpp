/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

struct milk {
    int tank1;
    int tank2;
    vector<int> milk1;
    vector<int> milk2;
    int abstraction; // 0 = Monday, 1 = Tuesday, 2 = Wednesday, 3 = Thursday, 4 = Friday
};

int main()
{
    ofstream fout ("backforth.out");
    ifstream fin ("backforth.in");
    // Brute Force
    milk m1;
    for(int i = 0; i < 10; i++) {
        int x;
        fin >> x;
        m1.milk1.push_back(x);
    }
    for(int i = 0; i < 10; i++) {
        int x;
        fin >> x;
        m1.milk2.push_back(x);
    }
    m1.abstraction = 0;
    m1.tank1 = 1000;
    m1.tank2 = 1000;
    vector<milk> unsolved;
    unsolved.push_back(m1);

    set <int, greater <int> > values;
    
    while(unsolved.size() > 0) {
        milk currentMilk = unsolved[0];

        int abstract = currentMilk.abstraction++;
        // odd = 1 -> 2, even = 1 <- 2
        
        if((abstract % 2) == 0) {
            for(int i = 0; i < currentMilk.milk2.size(); i++) {
                milk toAdd = currentMilk;
                toAdd.abstraction = abstract;
                toAdd.tank2 -= toAdd.milk2[i];
                toAdd.tank1 += toAdd.milk2[i];
                toAdd.milk1.push_back(toAdd.milk2[i]);
                toAdd.milk2.erase( toAdd.milk2.begin() + i);
                if(abstract == 4) {
                    values.insert(toAdd.tank1);
                } else {
                    unsolved.push_back(toAdd);
                }
                unsolved.erase(unsolved.begin());
            }
        } else {
            for(int i = 0; i < currentMilk.milk1.size(); i++) {
                milk toAdd = currentMilk;
                toAdd.abstraction = abstract;
                toAdd.tank1 -= toAdd.milk1[i];
                toAdd.tank2 += toAdd.milk1[i];
                toAdd.milk2.push_back(toAdd.milk1[i]);
                toAdd.milk1.erase( toAdd.milk1.begin() + i);
                if(abstract == 4) {
                    values.insert(toAdd.tank1);
                } else {
                    unsolved.push_back(toAdd);
                }
                unsolved.erase(unsolved.begin());
                
            }
        }
        

    }
       

    fout << values.size() << endl;
    return 0;
    
}