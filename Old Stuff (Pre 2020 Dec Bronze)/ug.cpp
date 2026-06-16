#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") { // See General -> Input/Output
	cin.tie(0)->sync_with_stdio(0); 
	if (int(name.size())) {
		freopen((name+".in").c_str(), "r", stdin); 
		freopen((name+".out").c_str(), "w", stdout);
	}
}

set<int> possible;

void search(int day, pair<int,vector<int> > x, pair<int,vector<int> > y) {
	if (day == 4) {
		possible.insert(x.first);
		return;
	}
	for(int i = 0; i < int((x.second).size()); i++){
		int t = x.second[i];
		vector<int> X = x.second; X.erase(begin(X) + i);
		vector<int> Y = y.second; Y.push_back(t);
		search(day + 1, {y.first + t, Y},{x.first - t, X});
	}
}

int main() {
	setIO("backforth");
	vector<int> a(10), b(10); 

	for(int i = 0; i < 10; i++) cin >> a[i];
	for(int i = 0; i < 10; i++) cin >> b[i];
	
	search(0, {1000, a}, {1000, b});
	cout << int(possible.size()) << endl;
}