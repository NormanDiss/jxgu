#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    adjacent_difference(a.begin(), a.end(), a.begin());
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}