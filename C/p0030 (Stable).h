/*
 https://projecteuler.net/problem=30
 */
#include <stdio.h>
#include <stdlib.h>
typedef long long int big;
int targetradix = 5;
int getnumbercount(big ref) {
 big base = 10;
 int ret = 1;
 while (((ref - (ref % base)) / base) > 0) {
  ret++;
  base *= 10;
  }
 return ret;
 }
int[] getlooplength() {
 big tmp = 0;
 int tmplen = 0;
 int ret[2];
 for (int a = 1; ret[0] == 0; a++) {
  tmp = 2;
  for (int b = 1; b < targetradix; a++) {
   tmp *= 2;
   }
  tmp *= a;
  tmplen = getnumbercount(tmp);
  if (tmplen == a) {
   ret[0] = tmplen;
   }
  }
 for (int a = 1; ret[1] == 0; a++) {
  tmp = 9;
  for (int b = 1; b < targetradix; a++) {
   tmp *= 9;
   }
  tmp *= a;
  tmplen = getnumbercount(tmp);
  if (tmplen == a) {
   ret[1] = tmplen;
   }
  }
 return ret;
 }
bool calculate(int[] numbers, int length) {
 big tmp = 0;
 big tmp2 = 0;
 for (int i = 0; i < length; i++) {
  tmp2 = numbers[i];
  for (int j = 1; j < targetradix; j++) {
   tmp2 *= numbers[i];
   }
  tmp += tmp2;
  }
 int numbercount = getnumbercount(tmp);
 if (numbercount != length) return false;
 int cachenumber = 0;
 int index = 0;
 while (tmp > 0) {
  cachenumber = (int)(tmp % 10);
  if (cachenumber != numbers[index]) return false;
  tmp -= cachenumber;
  tmp /= 10;
  index++;
  }
 return true;
 }
void sum(char* pool, int[] buffer, int poollen, int bufferlen) {
 int poolptr = 0;
 int remain = 0;
 for (int i = 0; i < bufferlen; i++) {
  if (poolptr == poollen) poollen++;
  remain = (*pool - '0') + buffer[i];
  *pool = (remain % 10) + '0';
  if (remain >= 10) {
   remain -= remain % 10;
   remain /= 10;
   }
  poolptr++;
  pool++;
  if (poolptr == poollen) {
   *pool = '0';
   }
  }
 if (remain > 0) {
  if (poolptr == poollen) poollen++;
  *pool = remain + '0';
  }
 pool -= poolptr;
 }
char* answer() {
 int length[] = getlooplength();
 char* ret = (char*)malloc(sizeof(char));
 *ret = '0';
 int retlen = 1;
 for (int i = length[0]; i <= length[1]; i++) {
  int buffer[i];
  buffer[i - 1] = 2;
  while (true) {
   if (calculate(buffer, i)) {
    sum(ret, buffer, retlen, i);
    }
   for (int j = 0; j < i && buffer[i - 1] != 0; j++) {
    buffer[j]++;
    if (buffer[j] == 10) {
     buffer[j] = 0;
     }
    else if (buffer[j] == 1) {
     buffer[j]++;
     }
    if (buffer[j] > 0) {
     break;
     }
    }
   if (buffer[i - 1] == 0) break;
   }
  }
 int retptr = 0;
 int retloop = (retlen % 1 == 0 ? retlen : retlen - 1) / 2;
 char tmp[2];
 for (int i = 0; i < retloop; i++) {
  tmp[0] = *ret;
  ret += retlen - 1 - (2 * i);
  tmp[1] = *ret;
  *ret = tmp[0];
  ret -= retlen - 1 - (2 * i);
  *ret = tmp[1];
  ret++;
  }
 ret -= retloop;
 return ret;
 }
int main(void) {
 printf("%s", answer());
 return 0;
 }
