/*
ID: ayushn.2
TASK: ratios
LANG: C++11
*/
#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    int r[3], a[3], b[3], c[3], current[3];
    float checkArr[3];
    int currentMin = 3000;
    int currentRatio = 0;
    ofstream fout ("ratios.out");
    ifstream fin ("ratios.in");

    for(int i = 0; i < 3; i++)
        fin >> r[i];
    for(int i = 0; i < 3; i++)
        fin >> a[i];
    for(int i = 0; i < 3; i++)
        fin >> b[i];
    for(int i = 0; i < 3; i++)
        fin >> c[i];


    for(int x = 0; x < 100; x++) {
        for(int y = 0; y < 100; y++) {
            for(int z = 0; z < 100; z++) {
                if((x + y + z) > currentMin)
                    continue;

                current[0] = (a[0] * x) + (b[0] * y) + (a[0] * z);
                current[1] = (a[1] * x) + (b[1] * y) + (a[1] * z);
                current[2] = (a[2] * x) + (b[2] * y) + (a[2] * z);

                // Now check if a ratio
                
                checkArr[0] = static_cast< float >(current[0]) / static_cast< float >(r[0]);
                checkArr[1] = static_cast< float >(current[1]) / static_cast< float >(r[1]);
                checkArr[2] = static_cast< float >(current[2]) / static_cast< float >(r[2]);
                if ( checkArr[0] == checkArr[1] && checkArr[1] == checkArr[2] && (x + y + z) != 0) {
                    currentRatio = checkArr[0]; // Check This!!!
                    currentMin = x + y + z;
                }
            }
        }
    }

    if(currentMin < 301) {
        cout << current[0] << " " << current[1] << " " << current[2] << " " << checkArr[0] << endl;

    } else {
        cout << "NONE";
    }
    return 0;
    
}