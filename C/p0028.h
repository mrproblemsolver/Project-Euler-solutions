/*
 https://projecteuler.net/problem=28
 */
#include <stdio.h>
int size = 1001;
long long int answer() {
 bool rleft = false;
 bool rright = false;
 bool rup = false;
 bool rdown = true;
 int next = 1;
 long long int ret = next;
 int increaser = 2;
 int loop = (size - 1) / 2;
 for (int i = 0; i < loop; i++) {
  while (true) {
   next += increaser;
   ret += next;
   rright = rup;
   rup = rleft;
   rleft = rdown;
   rdown = false;
   rdown = !(rleft || rdown || rup || rright);
   if (rdown) break;
   }
  increaser += 2;
  }
 return ret;
 }
int main(void) {
 printf("%lld", answer());
 return 0;
 }
