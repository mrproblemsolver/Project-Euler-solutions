#include <iostream>
#include <string>
using namespace std;

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

int answer() {
  int ret = 0;
  int tmp = 0;
  auto tmpstr = to_string(0);
  int last;
  int k = 0;
  bool verified = false;
  for (int i = 999; i > 0; i--) {
    for (int j = 999; j > 0; j--) {
      if (i < j) {
        j = i + 1;
        continue;
      }
      tmp = i * j;
      tmpstr = to_string(tmp);
      last = tmpstr.length() - 1;
      k = 0;
      verified = true;
      while (last > k) {
        if (tmpstr.at(k) != tmpstr.at(last)) {
          verified = false;
          break;
        }
        k++;
        last--;
      }
      if (verified) {
        if (tmp > ret) ret = tmp;
      }
    }
  }
  return ret;
}

int main()
{
    cout << answer() << "\n";
} 
