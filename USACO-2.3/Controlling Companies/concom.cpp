/*
ID: ayushn.2
TASK: concom    
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    int N;
    
    fin >> N;
    vector<vector<int> > businesses;
    for(int i = 0; i < N; i++) {
        vector<int> smh;
        smh.resize(3);
        fin >> smh[0];
        fin >> smh[1];
        fin >> smh[2];
        businesses.push_back(smh);
    }

    vector<vector<int> > ownership;

    // Calculate business number
    vector<int> vec;
    
    for (int i = 0; i < N; i++) {
        vec.push_back(businesses[i][0]);
        vec.push_back(businesses[i][1]);
    }

    sort( vec.begin(), vec.end() );
    int bNum = vec[vec.size()] + 1;
    ownership.resize(bNum);

    for(int i = 0; i < bNum; i++) {
        vector<int> assets;
        assets.resize(bNum);
        ownership[i] = assets;
    }


    for(int i = 0; i < businesses.size(); i++) {
        ownership[businesses[i][0]][businesses[i][1]] = businesses[i][2];
    }


    // for(int i = 1; i < ownership.size(); i++) {
    //     for(int j = 1; j < ownership[i].size(); j++) {
    //         cout << i << " " << j << " : " << ownership[i][j] << endl;
    //     }
    //     cout << endl;
    // }


    // Next check through all of its assets
    // cout << bNum << endl;

    for(int i = 1; i < ownership.size(); i++) {
        // For each business
        for(int j = 1; j < ownership[i].size(); j++) {
            // If controlled business > 50
            if(ownership[i][j] > 50) {
                // Copy over each value to the original
                for(int k = 0; k < ownership[j].size(); k++) {
                    ownership[i][k] += ownership[j][k];
                }
            }
        }
    }

    
    // cout << endl;
    // cout << endl;
    // for(int i = 1; i < ownership.size(); i++) {
    //     for(int j = 1; j < ownership[i].size(); j++) {
    //         cout << i << " " << j << " : " << ownership[i][j] << endl;
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i < ownership.size(); i++) {
        for(int j = 1; j < ownership[i].size(); j++) {
            if(i != j && ownership[i][j] > 50) {
                fout << i << j << endl;
            }
        }
    }

    return 0;
    
}