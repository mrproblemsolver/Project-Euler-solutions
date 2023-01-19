#include <iostream>
using namespace std;

//https://projecteuler.net/problem=15

int width = 20;
int height = 20;
int total(int rightcount, int downcount) {
 int ret = 0;
 if (rightcount == width && downcount == height) return ret + 1;
 else {
  if (rightcount < width) {
   ret += total(rightcount + 1, downcount);
   }
  if (downcount < height) {
   ret += total(rightcount, downcount + 1);
   }
  }
 return ret;
 }

int answer() {
 return total(0, 0);
 }

int main() {
 cout << answer() << endl;
 }
