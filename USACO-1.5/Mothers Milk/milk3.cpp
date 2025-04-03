/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct ABC {
    int A, B, C;
};

bool inVec(vector<ABC> find, ABC key) {
    for(int i = 0; i < find.size(); i++) {
        if(find[i].A == key.A && find[i].B == key.B && find[i].C == key.C) {
            return true;
        }
    }
    return false;
}

bool structEqual(ABC i1, ABC i2) {
    return(i1.A == i2.A && i1.B == i2.B && i1.C == i2.C);
}

vector<ABC> solve(ABC con, ABC cur) {
    vector<ABC> currentVec;
    // A to B
    if(cur.A + cur.B > con.B) {
        ABC val = {cur.A - (con.B - cur.B), con.B, cur.C};
        currentVec.push_back(val);
    } else {
        ABC val = {0, cur.A + cur.B, cur.C};
        currentVec.push_back(val);
    }
    // A to C
    if(cur.A + cur.C > con.C) {
        ABC val = {cur.A - (con.C - cur.C), cur.B, con.C};
        currentVec.push_back(val);
    } else {
        ABC val = {0, cur.B, cur.C + cur.A};
        currentVec.push_back(val);
    }
    // B to A
    if(cur.B + cur.A > con.A) {
        ABC val = {con.A, cur.B - (con.A - cur.A), con.C};
        currentVec.push_back(val);
    } else {
        ABC val = {cur.B + cur.A, 0, cur.C};
        currentVec.push_back(val);
    }
    // B to C
    if(cur.B + cur.C > con.C) {
        ABC val = {cur.A, cur.B - (con.C - cur.C), con.C};
        currentVec.push_back(val);
    } else {
        ABC val = {cur.A, 0,cur.C + cur.B};
        currentVec.push_back(val);
    }
    // C to A
    if(cur.C + cur.A > con.A) {
        ABC val = {con.A, cur.B, cur.C - (con.A - cur.A)};
        currentVec.push_back(val);
    } else {
        ABC val = {cur.C + cur.A, cur.B, 0};
        currentVec.push_back(val);
    }
    // C to B
    if(cur.C + cur.B > con.B) {
        ABC val = {cur.A, con.B, cur.C - (con.B - cur.B)};
        currentVec.push_back(val);
    } else {
        ABC val = {cur.A, cur.C + cur.B, 0};
        currentVec.push_back(val);
    }
    return currentVec;
}

int main()
{
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    int A, B, C;
    fin >> A;
    fin >> B;
    fin >> C;
    vector<ABC> nodes, unsolved;
    ABC Constructer = {A, B, C};
    ABC Init = {0, 0, C};
    nodes.push_back(Init);

    vector<ABC> z = solve(Constructer, Init);
    for(int i = 0; i < z.size(); i++) {
        if(inVec(nodes, z[i]) == false) {
            // Not in nodes
            nodes.push_back(z[i]);
            unsolved.push_back(z[i]);
        }
    }

    while(unsolved.size() > 0) {
        ABC toSolve = unsolved[0];
        // Solve and add to nodes and unsolved, 
        vector<ABC> z = solve(Constructer, toSolve);
        for(int i = 0; i < z.size(); i++) {
            if(inVec(nodes, z[i]) == false) {
                // Not in nodes
                nodes.push_back(z[i]);
                unsolved.push_back(z[i]);
            }
        }
        // Pop from unsolved
        for(int i = 0; i < unsolved.size(); i++) {
            if(structEqual(unsolved[i], toSolve)) {
                unsolved.erase(unsolved.begin() + (i + 1));
            }
        }
    }

    // for(int i = 0; i < nodes.size(); i++) {
    //     if(nodes[i].A == 0) {
    //         fout << nodes[i].C << " ";
    //     }
    // }
    // fout << endl;
    return 0;
    
}