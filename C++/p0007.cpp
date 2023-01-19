#include <iostream>
using namespace std;

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/

int target = 10001;
int answer() {
  int primes[target];
  primes[0] = 2;
  int counter = 1;
  int next = 3;
  bool verified = false;
  while (counter < target) {
    verified = true;
    for (int i = 0; i < counter; i++) {
      if (next % primes[i] == 0) {
        verified = false;
        break;
      }
    }
    if (verified) {
      primes[counter] = next;
      counter++;
    }
    next += 2;
  }
  return primes[target - 1];
}

int main()
{
    cout << answer() << "\n";
}
