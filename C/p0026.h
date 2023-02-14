/*
 https://projecteuler.net/problem=26
 */
#include <stdio.h>
#include <stdlib.h>
int maxnumber = 1000;
int[] divide(int number, int divider) {
 int ret[2];
 ret[0] = number * 10;
 if (number < divider) {
  ret[1] = 0;
  }
 else {
  int remain = ret[0] % divider;
  ret[1] = (ret[0] - remain) / divider;
  ret[0] = remain;
  }
 return ret;
 }
int getlength(int* remains, int* results, int remlastindex, int reslastindex) {
 int tmp[2] = {*remains, *results};
 int tmpremlastindex = remlastindex;
 int tmpreslastindex = reslastindex;
 int ret = 0;
 while (tmpremlastindex > 0) {
  tmpremlastindex--;
  tmpreslastindex--;
  remains--;
  results--;
  if (tmp[0] == *remains && tmp[1] == *results) {
   ret = remlastindex - tmpremlastindex;
   remains += ret;
   results += ret;
   return ret;
   }
  }
 remains += remlastindex;
 results += reslastindex;
 return ret;
 }
int answer() {
 int *remains = (int*)malloc(sizeof(int));
 int *results = (int*)malloc(sizeof(int));
 int remptr = 0;
 int resptr = 0;
 int ret = 0;
 int retlength = 0;
 int tmp[2];
 int tmp2 = 0;
 for (int i = 0; i < maxnumber; i++) {
  tmp[0] = 1;
  while (true) {
   tmp = divide(tmp[0], i);
   if (tmp[0] == 0) {
    break;
    }
   *remains = tmp[0];
   *results = tmp[1];
   if (resptr > 0) {
    tmp2 = getlength(remains, results, remptr, resptr);
    if (retlength < tmp2) {
     retlength = tmp2;
     break;
     }
    else if (tmp2 > 0) {
     tmp[0] = 0;
     break;
     }
    }
   remptr++;
   resptr++;
   remains++;
   results++;
   }
  if (tmp[0] != 0) {
   ret = i;
   }
  remains -= remptr;
  remptr = 0;
  results -= resptr;
  resptr = 0;
  }
 return ret;
 }
int main(void) {
 printf("%d", answer());
 return 0;
 }
