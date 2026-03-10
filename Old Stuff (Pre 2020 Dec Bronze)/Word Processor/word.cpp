#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream fin("word.in");
    ofstream fout("word.out");
    int N, K;
    vector<string> words;
    fin >> N >> K;
    words.resize(N);
    for(int i = 0; i < N; i++)
        fin >> words[i];
    
    int current = 0;
    for(int i = 0; i < N; i++) {
        // Check if empty
        if(current == 0) {
            fout << words[i];
            current += words[i].size();
            continue;
        } else {
            // Check if fits
            if((current + words[i].size()) <= K) {
                fout << " " << words[i];
                current += words[i].size();
            } else {
                current = words[i].size();
                fout << endl << words[i];
            }
        }
    }
    fout << endl;
    
    return 0;
}