#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	int N, cards[100001] = {0}, eCount = 0, ans;
	ifstream fin("highcard.in");
	ofstream fout("highcard.out");
	fin >> N;
	for(int i = 0; i < N; i++) {
		int z;
		fin >> z;
		cards[z] = 1;
	} 
	for(int i = 1; i <= 2*N; i++) {
		// cout << "card value: " << cards[i] << endl;
		if(cards[i] == 1) {
			eCount++;
		} else {
			if(eCount > 0) {
				eCount--;
			}
		}
		// cout << "eCount: " << eCount << endl; 
	}
	// eCount is the total maximum points won by Elsie
	ans = N - eCount;
	fout << ans << endl;
	return 0;
}
