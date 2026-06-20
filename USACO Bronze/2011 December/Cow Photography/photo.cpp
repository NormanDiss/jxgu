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
    ofstream fout ("X.out");
    ifstream fin ("X.in");
    int N;
    fin >> N;
    int photo1[5];
    int photo2[5];
    int photo3[5];
    int photo4[5];
    int photo5[5];
    for(int i = 0; i < N; i++) {
        fin >> photo1[i];
    }
    for(int i = 0; i < N; i++) {
        fin >> photo2[i];
    }
    for(int i = 0; i < N; i++) {
        fin >> photo3[i];
    }
    for(int i = 0; i < N; i++) {
        fin >> photo4[i];
    }
    for(int i = 0; i < N; i++) {
        fin >> photo5[i];
    }

    // Comapare 1 and 2, if bad 3
    if(photo1[0] == photo2[0]) {
        
    } else
    {
        if(photo3[0] == photo2[0]) {

        } else if(photo3[0] == photo1[0]) {

        } else {
            
        }
    }
    


    fout << "NotSetYet" << endl;
    return 0;
    
} 