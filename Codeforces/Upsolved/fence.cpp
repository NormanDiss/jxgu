#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N, arr[1000][3];
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	for(int i = 0; i < N; i++) {
		int theNum = 3 * ((arr[i][0] * arr[i][0]) + (arr[i][1] * arr[i][1]) + (arr[i][2] * arr[i][2]));
		for(int j = (arr[i][0] + arr[i][1] + arr[i][2]) - 1; j > 0; j--) {
			if((j * j) < theNum) {
				cout << j << endl;
				break;
			}
		}
	}
	
	return 0;
}
