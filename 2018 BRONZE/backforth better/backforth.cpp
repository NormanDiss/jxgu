#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

set<int> answers;

void friday(int milk, vector<int> b1, vector<int> b2) {
    for(int i = 0; i < b2.size(); i++) {
        answers.insert(milk + b2[i]);
    }
}

void thursday(int milk, vector<int> b1, vector<int> b2) {
    for(int i = 0; i < b1.size(); i++) {
        vector<int> x = b1; x.erase(x.begin() + i);
        vector<int> y = b2; y.push_back(b1[i]);
        friday(milk - b1[i], x, y);

    }
}

void wednesday(int milk, vector<int> b1, vector<int> b2) {
    for(int i = 0; i < b2.size(); i++) {
        vector<int> x = b2; x.erase(x.begin() + i);
        vector<int> y = b1; y.push_back(b2[i]);
        thursday(milk + b2[i], x, y);

    }
}

void tuesday(int milk, vector<int> b1, vector<int> b2) {
    for(int i = 0; i < b1.size(); i++) {
        vector<int> x = b1; x.erase(x.begin() + i);
        vector<int> y = b2; y.push_back(b1[i]);
        wednesday(milk - b1[i], x, y);

    }
}


int main() {
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    vector<int> b1, b2;
    b1.resize(10);
    b2.resize(10);
    for(int i = 0; i < 10; i++)
        fin >> b1[i];
    for(int i = 0; i < 10; i++)
        fin >> b2[i];
    tuesday(1000, b1, b2);


    cout << answers.size() << endl;
}