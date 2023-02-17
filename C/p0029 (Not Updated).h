/*
 https://projecteuler.net/problem=29
 */
#include <stdio.h>
#include <stdlib.h>
int mina = 2;
int maxa = 100;
int minb = 2;
int maxb = 100;
char* copy(char* ref, int length) {
 char *ret = (char*)malloc(sizeof(char));
 for (int i = 0; i < length; i++) {
  *ret = *ref;
  ret++;
  ref++;
  }
 ret -= length;
 ref -= length;
 return ret;
 }
char* exponentiation_multiplication_sub(char* ref1, int ref1len, char ref2) {
 char remain = '0';
 if (ref2 == '0') {
  char* retalt = (char*)malloc(sizeof(char));
  ref1len = 1;
  return retalt;
  }
 if (*ref1 == '0' && ref1len == 1) {
  char* retalt = (char*)malloc(sizeof(char));
  ref1len = 1;
  return retalt;
  }
 char* ret = copy(ref1, ref1len);
 for (int a = 0; a < ref1len; a++) {
  remain = remain + (*ref1 * ref2);
  *ret = remain % 10;
  remain -= *ret;
  remain /= 10;
  ref1++;
  ret++;
  }
 while (remain > 0) {
  *ret = remain % 10;
  remain -= *ret;
  remain /= 10;
  ref1++;
  ref1len++;
  ret++;
  }
 ref1 -= ref1len;
 ret -= ret1len;
 return ret;
 }
void exponentiation_multiplication(*char ref1, *char ref2, int ref1len, int ref2len) {
 char *sumcache[ref2len];
 int sumcachelen[ref2len];
 for (int a = 0; a < ref2len; a++) {
  sumcachelen[a] = ref1len;
  sumcache[a] = exponentiation_multiplication_sub(ref1, sumcachelen[a], *ref2);
  ref2++;
  }
 ref2 -= ref2len;
 int longest = 0;
 int remain = 0;
 for (int a = 0; a < ref2len; a++) {
  if (longest < sumcachelen[a]) longest = sumcachelen[a];
  }
 free(ref1);
 ref1 = (char*)malloc(sizeof(char));
 ref1len = 0;
 int loopstart = -1;
 for (int a = 0; a < longest; a++) {
  for (int b = loopstart < 0 ? 0 : loopstart; b < ref2len; b++) {
   if (a <= b && sumcachelen[b] > a) {
    remain += *sumcache[b];
    sumcache[b]++;
    }
   else if (sumcachelen[a] <= a) {
    if (loopstart == b - 1) loopstart = b;
    }
   }
  *ref1 = remain % 10;
  remain -= *ref1;
  remain /= 10;
  ref1++;
  ref1len++;
  }
 while (remain > 0) {
  *ref1 = remain % 10;
  remain -= *ref1;
  remain /= 10;
  ref1++;
  ref1len++;
  }
 *ref1 = '0';
 ref1 -= ref1len;
 for (int a = 0; a < ref2ptr; a++) {
  sumcache[a] -= sumcachelen[a];
  free(sumcache[a]);
  }
 }
void exponentiation(int a, int b, char* buffer, int bufferlen) {
 int refa = a;
 buffer = (char*)malloc(sizeof(char));
 if (b == 0 || a == 1) {
  *buffer = '1';
  bufferlen = 1;
  return;
  }
 if (a == 0) {
  bufferlen = 1;
  return;
  }
 bufferlen = 0;
 while (refa > 0) {
  *buffer = refa % 10;
  refa -= *buffer;
  refa /= 10;
  buffer++;
  bufferlen++;
  }
 buffer -= bufferlen;
 if (b == 1) return;
 char* ref2 = copy(buffer, bufferlen);
 int ref2len = bufferlen;
 for (int i = 2; i <= b; i++) {
  exponentiation_multiplication(buffer, ref2, bufferlen, ref2len);
  }
 }
bool compare(char* ref1, int len1, char* ref2, int len2) {
 if (len1 != len2) return false;
 for (int a = 0; a < len1; a++) {
  if (*ref1 != *ref2) {
   ref1 -= a;
   ref2 -= a;
   return false;
   }
  ref1++;
  ref2++;
  }
 ref1 -= len1;
 ref2 -= len2;
 return true;
 }
int answer() {
 int totalloop = (maxa - mina + 1) * (maxb - mina + 1);
 char *cache[totalloop];
 int lastlen[totalloop];
 int ret = 0;
 for (int a = mina; a <= maxa; a++) {
  for (int b = minb; b <= maxb; b++) {
   exponentiation(a, b, cache[ret], lastlen[ret]);
   for (int c = ret - 1; c >= 0; c--) {
    if (compare(cache[c], lastlen[c], cache[ret], lastlen[ret])) {
     free(cache[ret]);
     lastlen[ret] = 0;
     ret--;
     break;
     }
    }
   ret++;
   }
  }
 return ret;
 }
int main(void) {
 printf("%d", answer());
 return 0;
 }
