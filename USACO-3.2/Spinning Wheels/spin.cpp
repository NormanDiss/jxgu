/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct wedge {
    int start;
    int end;
};

struct wheel {
    int speed;
    int wedgeNum;
    vector<wedge> wedges;
};

bool checkGap(vector<wheel> toCheck) {
    for(int i = 0; i < 360; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < toCheck[j].wedgeNum; k++) {
                
            }
        }
    }
}

int main()
{
    ofstream fout ("spin.out");
    ifstream fin ("spin.in");
    vector<wheel> smh;
    for(int i = 0; i < 5; i++) {
        wheel s;
        fin >> s.speed >> s.wedgeNum;
        for(int j = 0; j < s.wedgeNum; j++) {
            wedge x;
            fin >> x.start >> x.end;
            s.wedges.push_back(x);
        }
        smh.push_back(s);
    }
    // Everything gathered

    vector<wheel> current = smh;
    int cnt = 0;
    while (true) {
        // First Check 
        if(checkGap(current)) {
            cout << cnt << endl;
            return 0;
        }
        // Then Update
        for(int i = 0; i < 5; i++) {
            wheel x = current[i];
            for(int j = 0; j < x.wedgeNum; j++) {
                int a = x.wedges[j].start + x.speed;
                int b = x.wedges[j].end + x.speed;
                x.wedges[j].start = a % 360;
                x.wedges[j].end = b % 360;
            }
            current[i] = x;
        }
        cnt ++;
        // Check if Original
        bool original = false;
        for(int i = 0; i < 5; i++) {

            for(int j = 0; j < current[i].wedgeNum; j++) {

                if(current[i].wedges[j].start != smh[i].wedges[j].start) {
                    original = true;
                    break;

                } 

                if(current[i].wedges[j].start != smh[i].wedges[j].start) {
                    original = true;
                    break;
                }
            }
            if(original == true)
                break;
        }
        if(original == false) {
            cout << "none" << endl;
            cout << cnt << endl;
            return 0;
        }

    }

    fout << "NotSetYet" << endl;
    return 0;
    
}