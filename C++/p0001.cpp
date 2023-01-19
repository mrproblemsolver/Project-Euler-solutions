#include <iostream>
using namespace std;

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

int n = 1000;
int m = 1;
int primes[] = {3, 5};
int answer() {
  bool checked = false;
  int sum = 0;
  int plen = sizeof(primes)/sizeof(primes[0]);
  for (int a = m ; a < n; a++) {
    checked = false;
    for (int b = 0; b < plen; b++) {
      if (a % primes[b] == 0) {
        checked = true;
        break;
      }
    }
    if (checked) {
        sum += a;
    }
  }
  return sum;
}
int main()
{
    cout << answer();
}
