/*
 https://projecteuler.net/problem=27
 */
#include <stdio.h>
int maxa = 999;
int mina = -999;
int maxb = 1000;
int minb = -1000;
bool isprime(long long int result) {
 long long int n = result;
 if (n < 0) n = n * -1;
 if (n <= 1) return false;
 if (n % 2 == 0) return false;
 for (long long int i = 3; (i * i) < n; i += 2) {
  if (n % i == 0) return false;
  }
 return (i * i) != n;
 }
long long int answer() {
 int b = 0;
 int n = 0;
 bool processloop = false;
 long long int result = 0;
 long long int ret = 0;
 int maxn = -1;
 for (int a = mina; a <= maxa; a++) {
  for (b = minb; b <= maxb; b++) {
   acceptableloop = true;
   processloop = false;
   for (n = 0; acceptableloop; n++) {
    result = (n*n)+(n*a)+b;
    acceptableloop = isprime(result);
    if (acceptableloop) processloop = true;
    }
   n = n - 2;
   if (n > maxn) {
    maxn = n;
    ret = maxn * b;
    if (ret < 0) ret = ret * -1;
    }
   if (processloop) {
    acceptableloop = true;
    for (n = 0; acceptableloop; n--) {
     result = (n*n)+(n*a)+b;
     acceptableloop = isprime(result);
     }
    n = (n + 2) * -1;
    if (n > maxn) {
     maxn = n;
     ret = maxn * b;
     if (ret < 0) ret = ret * -1;
     }
    }
   }
  }
 return ret;
 }
int main(void) {
 printf("%lld", answer());
 return 0;
 }
