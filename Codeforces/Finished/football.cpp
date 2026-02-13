#include <iostream>
#include <string>

using namespace std;

int main() {
	string x;
	cin >> x;
	int currentMax = 0, strSize = x.size();
	for(int i = 0; i < strSize; i++) {
		if(x[i] == '1') currentMax++;
		else currentMax = 0;
		if(currentMax == 7) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
