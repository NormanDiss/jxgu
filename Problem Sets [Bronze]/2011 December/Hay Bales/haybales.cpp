/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++                 
*/


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout ("haybales.out");
    ifstream fin ("haybales.in");
    int N;
    fin >> N;
    int bales[N];
    for(int i = 0; i < N; i++) {
        fin >> bales[i];
    }

    // Find the Average
    int avg;
    int sum;
    for(int i = 0; i < N; i++) {
        sum += bales[i];
    }
    avg = sum/N;

    // Now basically find the discrepancies from avg (If over avg, then must be moved so added to total)
    int total = 0;
    for(int i = 0; i < N; i++) {
        if(bales[i] > avg) {
            total += (bales[i] - avg);
        }
    }
    fout << total << endl;
    return 0;
    
}