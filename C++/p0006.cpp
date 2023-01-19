#include <iostream>
using namespace std;

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

int maxdivider = 20;
int answer() {
  int ret = maxdivider;
  bool verified = true;
  while (true) {
    verified = true;
    for (int i = 2; i <= maxdivider; i++) {
      if (ret % i != 0) {
        verified = false;
        ret += maxdivider;
        break;
      }
    }
    if (verified) {
      break;
    }
  }
  return ret;
}
int main()
{
    cout << answer() << "\n";
} 
