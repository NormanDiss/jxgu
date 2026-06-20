#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
    // ifstream cin("concert.in");
    int N, M; cin >> N >> M;
    set<int> s;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        s.insert(a);
    }
    // To insert smallest element
    s.insert(-1);
    for(int i = 0; i < M; i++) {
        int tmp; cin >> tmp;
        auto iter = s.upper_bound(tmp);
        int number = *(--iter);
        if(number == -1) {
            cout << -1 << '\n';
        } else {
            cout << number << '\n';
            s.erase(iter);
        }
    }
    
}

