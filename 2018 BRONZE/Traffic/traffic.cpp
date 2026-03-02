#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");
    int N, refocus[2] = {0}, backArr[100][2], refoci[2] = {0};
    string foreArr[100];
    fin >> N;
    for(int i = 0; i < N; i++) {
        string s;
        int x, y;
        fin >> s >> x >> y;
        backArr[i][0] = x;
        backArr[i][1] = y;
        foreArr[i] = s;
        // cout << s << " " << x << " " << y << endl;
        if(s == "on") {
            refocus[0]+= x;
            refocus[1] += y;
            // cout << "add"<< endl;
        }   
        if(s == "off") {
            refocus[0] -= y;
            refocus[1] -= x;
        // cout << "subtract"<< endl;
        }
        if(s == "none") {
            if(refocus[0] < x)
                refocus[0] = x;
            if(refocus[1] > y)
                refocus[1] = y;

            if(refocus[1] < x) // this case will only happen with adds and subtracts before
                refocus[1] = y;
            // cout << "refocus"<< endl;

        }
        // cout << refocus[0] << " " << refocus[1] << endl;
    }

    for(int i = N - 1; i >= 0; i--) {
        int x = backArr[i][0], y = backArr[i][1];
        string s = foreArr[i];
        if(s == "on") {
            refoci[0] -= y;
            refoci[1] -= x;
        }
        if(s == "off") {
            refoci[0] += x;
            refoci[1] += y;
        }
        if(s == "none") {
            if(refoci[0] < x)
                refoci[0] = x;
            if(refoci[1] > y)
                refoci[1] = y;

            if(refoci[1] < x)
                refoci[1] = y;
        }
        // cout << refoci[0] << " " << refoci[1] << endl;


    }
    fout << refoci[0] << " " << refoci[1] << endl;
    fout << refocus[0] << " " << refocus[1] << endl;


    return 0;
}