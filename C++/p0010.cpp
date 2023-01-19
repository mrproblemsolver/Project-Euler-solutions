#include <iostream>
using namespace std;

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
  
long int reference = 2000000;
bool isprime(long int ref) {
    long int i = 2;
    long int n = ref;
    if (n % i == 0) return false;
    else {
      i = 3;
    }
    while ((i * i) <= n) {
         if (n % i == 0)  return false;
         i += 2;
    }
    return true;
}
long int answer() {
  long int ret = 2;
  for (long int i = 3; i < reference; i += 2) {
    if (isprime(i)) ret += i;
  }
  return ret;
}

int main()
{
    cout << answer() << endl;
} 
