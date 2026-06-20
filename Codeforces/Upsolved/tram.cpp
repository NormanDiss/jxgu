#include <iostream>

using namespace std;

int main()
{
  int n, current = 0, cmax = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    current -= temp;
    cin >> temp;
    current += temp;
    if(current > cmax)
      cmax = current;
  }
cout << cmax << endl;
    
  return 0;
}
