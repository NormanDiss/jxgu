#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    int N, finished = 0, unique = 0;
    string correct[1000], known[1000];
    fin >> N;
    for(int i = 0; i < N; i++)
        fin >> correct[i];

    for(int i = 0; i < N; i++)
        fin >> known[i];
    
    for(int i = 0; i < N; i++) {
        if(correct[i] != known[i]) {
            finished++;
            cout << i <<  " mismatch " << finished << endl;
        } else {
            if(finished != 0) {
                finished = 0;
                unique++;
            }
        }
        
    }
    cout << unique << endl;

}