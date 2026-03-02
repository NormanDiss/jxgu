#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

struct barns {
    vector<int> Barn1;
    vector<int> Barn2;
    int abstract, m1, m2; 
};

int main() {
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    barns first;
    first.Barn1.resize(10);
    first.Barn2.resize(10);
    first.abstract = 1;
    first.m1 = 1000;
    first.m2 = 1000;
    set<int> values;
    
    for(int i = 0; i < 10; i++)
        fin >> first.Barn1[i];
    
    for(int i = 0; i < 10; i++)
        fin >> first.Barn2[i];

    vector<barns> unsolved;
    unsolved.push_back(first);

    int max_size = 0;

    while(unsolved.size() > 0) {
        if(unsolved.size() > max_size) 
            max_size = unsolved.size();

        barns current = unsolved[0];
        if(current.abstract == 5) {
            values.insert(current.m1);
        } else {
            if(current.abstract % 2 == 0) {
                // even use second one
                for(int i = 0; i < current.Barn2.size(); i++) {
                    barns y = current;
                    y.Barn1.push_back(y.Barn2[i]);
                    y.m2 -= y.Barn2[i];
                    y.m1 += y.Barn2[i];
                    y.Barn2.erase(y.Barn2.begin() + i);
                    y.abstract++;
                    unsolved.push_back(y);
                }
            } else {
                // odd use first one
                for(int i = 0; i < current.Barn1.size(); i++) {
                    barns y = current;
                    y.Barn2.push_back(y.Barn1[i]);
                    y.m1 -= y.Barn1[i];
                    y.m2 += y.Barn1[i];
                    y.Barn1.erase(y.Barn1.begin() + i);
                    y.abstract++;
                    unsolved.push_back(y);
                }

            }
        }
        unsolved.erase(unsolved.begin());
    }
   
   cout << values.size() << endl;
   cout << max_size << endl;


}