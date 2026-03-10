#include <iostream>

using namespace std;

string wordAbbrev(string input) {
    if(input.size() > 10) {
        string s = "";
        s += input.at(0);
        s += to_string(input.size() - 2);
        s += input.at(input.size() - 1);
        return s;
    }
    return input;
}

int main()
{
    int n;
    cin >> n;
    string x[n];
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        x[i] = wordAbbrev(s);
    }
    for(int i = 0; i < n; i++) {
        cout << x[i] << endl;
    }

    return 0;
}
