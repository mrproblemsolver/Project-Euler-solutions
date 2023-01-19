#include <iostream>
using namespace std;

/*
https://projecteuler.net/problem=9
*/

int total = 1000;
int answer() {
  for (int a = 2; a < total; a++) {
    for (int b = 2; b < total; b++) {
      for (int c = 2; c < total; c++) {
        if ((a * a) + (b * b) == (c * c)) {
          if (a + b + c == total) {
            return a * b * c;
          }
        }
      }
    }
  }
  return 1;
}

int main()
{
    cout << answer() << endl;
} 
