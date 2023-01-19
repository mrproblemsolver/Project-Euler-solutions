#include <iostream>
using namespace std;

/*
https://projecteuler.net/problem=6
*/

int maxloop = 100;
int answer() {
  int first = 0;
  int second = 0;
  for (int i = 1; i <= maxloop; i++) {
    first += i * i;
    second += i;
  }
  second *= second;
  return second - first;
}
int main()
{
    cout << answer() << "\n";
} 
