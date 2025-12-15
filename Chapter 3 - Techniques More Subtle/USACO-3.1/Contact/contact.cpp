/*
ID: ayushn.2
TASK: contact
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct num {
    string part;
    int freq;
};


int main()
{
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
    int A, B, N;
    fin >> A >> B >> N;
    string s = "";
    while(fin) {
        string x;
        fin >> x;
        s += x;
    }
    vector<string> strings;
    // Method -> just add everything to a list, order that list and BOOM done.
    cout << s.length() << endl;
    for(int i = 0; i < s.length(); i++) {
        for(int j = 0; j < B; j++){
            string construct = "";
            for(int x = 0; x < j; x++) {
                construct += s.at(i + x);
            }
            strings.push_back(construct);
        }
    }

    sort(strings.begin(), strings.end());
    int cnt = 0;
    int crrCnt = 0;
    string curritem = "";
    while(cnt > strings.size()) {
        if(strings[cnt] != curritem) {
            fout << curritem << endl;
            cout << crrCnt << endl;
            crrCnt = 0;
            curritem = strings[cnt];
        }
        cnt++;

    }
    
    fout << strings[-1] << endl;
    return 0;
    
}