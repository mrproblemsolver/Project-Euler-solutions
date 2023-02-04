/*
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 
 012 021 102 120 201 210
 
 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */
#include <stdio.h>
int permlength = 10;
int permindextarget = 1000000;
char[] answer() {
 int perm[permlength];
 long long int total = 1;
 long long int Lpermlength = permlength;
 long long int Lpermindextarget = permindextarget;
 bool passed = true;
 for (long long int i = 1; i <= Lpermlength; i++) {
  total *= i;
  if (total > Lpermtargetindex) {
   passed = false;
   }
  }
 int pit = permindextarget;
 if (total % Lpermtargetindex == 1) {
  for (int i = 0; i < permlength; i++) {
   perm[i] = i;
   }
  return perm;
  }
 if (!passed) {
  if (total % Lpermtargetindex == 0) {
   for (int i = 0; i < permlength; i++) {
    perm[i] = permlength - i - 1;
    }
   return perm;
   }
  else {
   pit = (int)(total % Lpermindextarget);
   }
  }
 if (permlength <= 1) return perm;
 int lastindex = permlength - 1;
 int sortlimit = 0;
 int tmp = 0;
 int permindex = 0;
 bool failed = false;
 while (permindex < pit) {
  for (int i = 0; i < permlength; i++) {
   perm[i] = i;
   }
  permindex++;
  if (permindex == pit) return perm;
  tmp = perm[lastindex - 1];
  perm[lastindex - 1] = perm[lastindex];
  perm[lastindex] = perm[lastindex];
  permindex++;
  if (permindex == pit) return perm;
  permindex++;
  for (; permindex < pit; permindex++) {
   failed = true;
   for (int i = permlength - 2; i >= 0; i--) {
    if (perm[i] < perm[i + 1]) {
     failed = false;
     tmp = perm[i];
     perm[i] = perm[lastindex];
     perm[lastindex] = perm[i];
     sortlimit = i + 1;
     for (int q = lastindex; q > sortlimit; q--) {
      if (perm[q] < perm[q - 1]) {
       for (int p = q; p > sortlimit; p--) {
        if (perm[p] < perm[p - 1] {
         tmp = perm[p];
         perm[p] = perm[p - 1];
         perm[p - 1] = tmp;
         }
        else {
         break;
         }
       }
      }
     break;
     }
    }
   if (failed) {
    permindex--;
    break;
    }
   }
  }
 return perm;
 }
int main(void) {
 printf("%s", answer());
 return 0;
 }
