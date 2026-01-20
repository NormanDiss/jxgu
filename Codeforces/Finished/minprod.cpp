#include <iostream>

using namespace std;

int main() {

  int N, maze[10000];
  cin >> N;
  for(int i = 0; i < N; i++) {
     int a, b, x, y, n, aMod = a, bMod = b;
     cin >> a >> b >> x >> y >> n;
     if(b > a) {
       if((a - x) >= n) {
         aMod = a - n;
         bMod = b;
       }  else {
         aMod = n;
         bMod = (b - (n - (a - x)));
       }
     } else if(a > b) {
       if((b - y)>= n) {
          bMod = b - n;
          aMod = a;
       } else {
          bMod = n;
          aMod = (a - (n - (b - y)));
       }
     } else {
       // a == b
       if((b - y) > (a - x)) {
         // subtract from b
          if((b - y)>= n) {
              bMod = b - n;
              aMod = a;
          } else {
              bMod = n;
              aMod = (a - (n - (b - y)));
          }  
       } else {
            // subtract from a
          if((a - x) >= n) {
            aMod = a - n;
            bMod = b;
          }  else {
            aMod = n;
            bMod = (b - (n - (a - x)));
          }
       } 
        if(aMod < x) {
          aMod = x;
        }
        if(bMod < y) {
          bMod = y;
        }
    maze[i] = bMod * aMod;
  }
}
  for(int i = 0; i < N; i++) {
    cout << maze[i] << endl;
  }
  return 0;
}
