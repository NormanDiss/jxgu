//First App
#include <iostream>
using std::cout;
using std::endl;

int main() {
    int i1 = 1;
    cout << i1 << endl;
    int i2;
    i2 = 2;
    cout << i2 << endl;

    double d1 = 2.2;
    cout << d1 << endl;
    int i5 = static_cast<int>(d1);
    cout << i5 << endl;

    char c1 = 'a';
    cout << c1 << endl;

    bool flag = false;
    cout << flag << endl;
    flag = d1;
    cout << flag << endl;
}
