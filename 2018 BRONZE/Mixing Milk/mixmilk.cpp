#include <iostream>
#include <fstream>

using namespace std;
int x[3];

void pour(int abs, int num, int m1, int m2, int m3, int c1, int c2, int c3) {
    if(abs == 1) {
        // from 1 -> 2  
        m2 += m1;
        m1 = 0;
        m1 += (m2 - c2);

        if(m1 < 0)
            m1 = 0;
        
        if(m2 > c2)
            m2 = c2;

    } else if(abs == 2) {
        // from 2 -> 3
        m3 += m2;
        m2 = 0;
        m2 += (m3 - c3);
        
        if(m2 < 0)
            m2 = 0;
        
        if(m3 > c3)
            m3 = c3;
    } else {
        // from 3 -> 1
        m1 += m3;
        m3 = 0;
        m3 += (m1 - c1);
        
        if(m3 < 0)
            m3 = 0;
        
        if(m1 > c1)
            m1 = c1;
    }
    abs++;
    abs = abs % 3;
    num++;
    if(num == 101) {
        x[0] = m1;
        x[1] = m2;
        x[2] = m3;
    } else {
        pour(abs, num, m1, m2, m3, c1, c2, c3);
    }
    
}

int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    int m1, m2, m3;
    int c1, c2, c3;
    fin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    pour(0, 0, m1, m2, m3, c1, c2, c3);
    // cout << x[0] << endl << x[1] << endl << x[2] << endl;
    fout << x[0] << endl << x[1] << endl << x[2] << endl;

}